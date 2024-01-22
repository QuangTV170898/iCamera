/*
 * Copyright 2021 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "bd_venc.h"
#include "bd_log.h"

#include "bd_common.h"
#include "sdk_common.h"
#include "webrtc_common.h"
#include "webrtc.h"
#include <imp/imp_log.h>
#include <imp/imp_common.h>
#include <imp/imp_system.h>
#include <imp/imp_framesource.h>
#include <imp/imp_encoder.h>
#include <imp/imp_isp.h>
#include <imp/imp_osd.h>

#define T31_VIDEO_STREAM_1080P_CHANNEL_NUM 0
#define T31_VIDEO_STREAM_720P_CHANNEL_NUM 1
#define T31_VIDEO_STREAM_LOW_RES_CHANNEL_NUM 2
#define T31_VIDEO_STREAM_CHANNEL_NUM 3
#define VIDEO_FRAME_BUFFER_SIZE_BYTES (256 * 1024UL)

#define T31_HANDLE_GET(x) bd_venc_context_t *t31_handle = (bd_venc_context_t *)((x))

typedef struct
{
    BD_VENC_STATUS_E status;
    BD_VENC_FMT_E format;
    BD_VENC_RESOLUTION_E resolution;
    bd_venc_capability_t capability;
    uint8_t channelNum;
} bd_venc_context_t;

extern struct chn_conf chn[];
static volatile size_t t31VideoSystemUser = 0;

static int _set_status(bd_venc_handle handle, const BD_VENC_STATUS_E n_status)
{
    T31_HANDLE_NULL_CHECK(handle);
    T31_HANDLE_GET(handle);

    if (n_status != t31_handle->status)
    {
        t31_handle->status = n_status;
        LOG("VideoCapturer new status[%d]", n_status);
    }

    return 0;
}

static int _get_packet(IMPEncoderStream *pStream, IMPEncoderPack *pPack, uint8_t *pPacketBuf, size_t uPacketSize)
{
    if (pStream == NULL || pPack == NULL || pPacketBuf == NULL || uPacketSize == 0 || pPack->length == 0)
    {
        return -EINVAL;
    }

    /*  virAddr is a ringbuffer, and the packet may be cut into 2 pieces. */
    uint32_t uRemainingSize = pStream->streamSize - pPack->offset;

    if (uRemainingSize < pPack->length)
    {
        /* The packet is cut into 2 pieces. */
        memcpy(pPacketBuf, (uint8_t *)(pStream->virAddr + pPack->offset), uRemainingSize);
        memcpy(pPacketBuf + uRemainingSize, (uint8_t *)(pStream->virAddr), pPack->length - uRemainingSize);
    }
    else
    {
        /* The packet is a complete one. */
        memcpy(pPacketBuf, (uint8_t *)(pStream->virAddr + pPack->offset), pPack->length);
    }

    return 0;
}

static int _start_recv_frame(bd_venc_handle handle, uint8_t chnNum)
{
    T31_HANDLE_NULL_CHECK(handle);
    T31_HANDLE_GET(handle);

    T31_HANDLE_STATUS_CHECK(t31_handle, BD_VENC_STATUS_STREAM_ON);

    if (t31_handle->format != VID_FMT_RAW)
    {
        if (IMP_Encoder_StartRecvPic(chnNum))
        {
            LOG("IMP_Encoder_StartRecvPic(%d) failed", chnNum);
            return -EAGAIN;
        }

        LOG("IMP_Encoder_StartRecvPic(%d)", chnNum);
    }
    else
    {
        if (IMP_FrameSource_SetFrameDepth(t31_handle->channelNum, chn[t31_handle->channelNum].fs_chn_attr.nrVBs * 2))
        {
            LOG("IMP_FrameSource_SetFrameDepth(%d,%d) failed", t31_handle->channelNum, chn[t31_handle->channelNum].fs_chn_attr.nrVBs * 2);
            return -EAGAIN;
        }
    }

    return 0;
}

static int _stop_recv_frame(bd_venc_handle handle, uint8_t chnNum)
{
    T31_HANDLE_NULL_CHECK(handle);
    T31_HANDLE_GET(handle);

    if (t31_handle->format != VID_FMT_RAW)
    {
        if (IMP_Encoder_StopRecvPic(chnNum))
        {
            LOG("IMP_Encoder_StopRecvPic(%d) failed", chnNum);
            return -EAGAIN;
        }

        LOG("IMP_Encoder_StopRecvPic(%d)", chnNum);
    }
    else
    {
        IMP_FrameSource_SetFrameDepth(t31_handle->channelNum, 0);
    }

    return 0;
}

bd_venc_handle bd_venc_create(void)
{
    bd_venc_context_t *t31_handle = NULL;

    if (!(t31_handle = (bd_venc_context_t *)malloc(sizeof(bd_venc_context_t))))
    {
        LOG("OOM");
        return NULL;
    }

    memset(t31_handle, 0, sizeof(bd_venc_context_t));

    if (!t31VideoSystemUser)
    {
        for (int i = 0; i < T31_VIDEO_STREAM_CHANNEL_NUM; i++)
        {
            chn[i].enable = false;
        }
        /* Step.1 System init */
        if (sample_system_init())
        {
            LOG("IMP_System_Init() failed");
            free(t31_handle);
            return NULL;
        }
    }

    // Now implementation supports H.264, RAW(NV12), 1080p, 720p, 480p, 360p and 320p
    t31_handle->capability.formats = (1 << (VID_FMT_H264 - 1)) | (1 << (VID_FMT_RAW - 1));
    t31_handle->capability.resolutions =
        (1 << (VID_RES_1080P - 1)) | (1 << (VID_RES_720P - 1)) | (1 << (VID_RES_480P - 1)) | (1 << (VID_RES_360P - 1)) | (1 << (VID_RES_320P - 1));

    _set_status((bd_venc_handle)t31_handle, BD_VENC_STATUS_STREAM_OFF);

    ATOMIC_INT_ADD(&t31VideoSystemUser);

    return (bd_venc_handle)t31_handle;
}

BD_VENC_STATUS_E bd_venc_set_status(const bd_venc_handle handle)
{
    if (!handle)
    {
        return BD_VENC_STATUS_NOT_READY;
    }

    T31_HANDLE_GET(handle);
    return t31_handle->status;
}

int bd_venc_get_capability(const bd_venc_handle handle, bd_venc_capability_t *pCapability)
{
    T31_HANDLE_NULL_CHECK(handle);
    T31_HANDLE_GET(handle);

    if (!pCapability)
    {
        return -EAGAIN;
    }

    *pCapability = t31_handle->capability;

    return 0;
}

int bd_venc_set_config(bd_venc_handle handle, const BD_VENC_FMT_E format, const BD_VENC_RESOLUTION_E resolution)
{
    T31_HANDLE_NULL_CHECK(handle);
    T31_HANDLE_GET(handle);

    T31_HANDLE_STATUS_CHECK(t31_handle, BD_VENC_STATUS_STREAM_OFF);

    switch (resolution)
    {
    case VID_RES_1080P:
        t31_handle->channelNum = T31_VIDEO_STREAM_1080P_CHANNEL_NUM;
        break;
    case VID_RES_720P:
        t31_handle->channelNum = T31_VIDEO_STREAM_720P_CHANNEL_NUM;
        break;

    case VID_RES_480P:
        t31_handle->channelNum = T31_VIDEO_STREAM_LOW_RES_CHANNEL_NUM;
        chn[t31_handle->channelNum].fs_chn_attr.picWidth = 640;
        chn[t31_handle->channelNum].fs_chn_attr.picHeight = 480;
        chn[t31_handle->channelNum].fs_chn_attr.scaler.enable = 1;
        chn[t31_handle->channelNum].fs_chn_attr.scaler.outwidth = chn[t31_handle->channelNum].fs_chn_attr.picWidth;
        chn[t31_handle->channelNum].fs_chn_attr.scaler.outheight = chn[t31_handle->channelNum].fs_chn_attr.picHeight;
        break;

    case VID_RES_360P:
        t31_handle->channelNum = T31_VIDEO_STREAM_LOW_RES_CHANNEL_NUM;
        chn[t31_handle->channelNum].fs_chn_attr.picWidth = 480;
        chn[t31_handle->channelNum].fs_chn_attr.picHeight = 360;
        chn[t31_handle->channelNum].fs_chn_attr.scaler.enable = 1;
        chn[t31_handle->channelNum].fs_chn_attr.scaler.outwidth = chn[t31_handle->channelNum].fs_chn_attr.picWidth;
        chn[t31_handle->channelNum].fs_chn_attr.scaler.outheight = chn[t31_handle->channelNum].fs_chn_attr.picHeight;
        break;
    case VID_RES_320P:
        t31_handle->channelNum = T31_VIDEO_STREAM_LOW_RES_CHANNEL_NUM;
        chn[t31_handle->channelNum].fs_chn_attr.picWidth = 416;
        chn[t31_handle->channelNum].fs_chn_attr.picHeight = 320;
        chn[t31_handle->channelNum].fs_chn_attr.scaler.enable = 1;
        chn[t31_handle->channelNum].fs_chn_attr.scaler.outwidth = chn[t31_handle->channelNum].fs_chn_attr.picWidth;
        chn[t31_handle->channelNum].fs_chn_attr.scaler.outheight = chn[t31_handle->channelNum].fs_chn_attr.picHeight;
        break;

    default:
        LOG("Unsupported resolution %d", resolution);
        return -EINVAL;
    }

    switch (format)
    {
    case VID_FMT_H264:
        chn[t31_handle->channelNum].payloadType = IMP_ENC_PROFILE_AVC_MAIN;
        break;
    case VID_FMT_RAW:
        break;

    default:
        LOG("Unsupported format %d", format);
        return -EINVAL;
    }
    chn[t31_handle->channelNum].enable = true;

    /* Step.2 FrameSource init */

    if (IMP_FrameSource_CreateChn(chn[t31_handle->channelNum].index, &chn[t31_handle->channelNum].fs_chn_attr))
    {
        LOG("IMP_FrameSource_CreateChn(chn%d) error !", chn[t31_handle->channelNum].index);
        return -EAGAIN;
    }

    if (IMP_FrameSource_SetChnAttr(chn[t31_handle->channelNum].index, &chn[t31_handle->channelNum].fs_chn_attr))
    {
        LOG("IMP_FrameSource_SetChnAttr(chn%d) error !", chn[t31_handle->channelNum].index);
        return -EAGAIN;
    }

    if (format != VID_FMT_RAW)
    {
        /* Step.3 Encoder init */

        if (IMP_Encoder_CreateGroup(chn[t31_handle->channelNum].index))
        {
            LOG("IMP_Encoder_CreateGroup(%d) error !", chn[t31_handle->channelNum].index);
            return -EAGAIN;
        }

        if (sample_encoder_init())
        {
            LOG("Encoder init failed");
            return -EAGAIN;
        }

        /* Step.4 Bind */
        if (IMP_System_Bind(&chn[t31_handle->channelNum].framesource_chn, &chn[t31_handle->channelNum].imp_encoder))
        {
            LOG("Bind FrameSource channel%d and Encoder failed", t31_handle->channelNum);
            return -EAGAIN;
        }
    }

    t31_handle->format = format;
    t31_handle->resolution = resolution;

    return 0;
}

int bd_venc_get_config(const bd_venc_handle handle, BD_VENC_FMT_E *pFormat, BD_VENC_RESOLUTION_E *pResolution)
{
    T31_HANDLE_NULL_CHECK(handle);
    T31_HANDLE_GET(handle);

    *pFormat = t31_handle->format;
    *pResolution = t31_handle->resolution;

    return 0;
}

int bd_venc_enable_stream(bd_venc_handle handle)
{
    T31_HANDLE_NULL_CHECK(handle);
    T31_HANDLE_GET(handle);

    if (IMP_FrameSource_EnableChn(chn[t31_handle->channelNum].index))
    {
        LOG("IMP_FrameSource_EnableChn(%d) error", chn[t31_handle->channelNum].index);
        return -EAGAIN;
    }

    _set_status(handle, BD_VENC_STATUS_STREAM_ON);
    return _start_recv_frame(handle, t31_handle->channelNum);
}

int bd_venc_get_frame(bd_venc_handle handle, void *pFrameDataBuffer, const size_t frameDataBufferSize, uint64_t *pTimestamp,
                      size_t *pFrameSize)
{
    T31_HANDLE_NULL_CHECK(handle);
    T31_HANDLE_GET(handle);

    T31_HANDLE_STATUS_CHECK(t31_handle, BD_VENC_STATUS_STREAM_ON);

    if (!pFrameDataBuffer || !pTimestamp || !pFrameSize)
    {
        return -EINVAL;
    }

    int ret = 0;

    if (t31_handle->format == VID_FMT_RAW)
    {
        IMPFrameInfo *rawFrame = NULL;
        if (IMP_FrameSource_GetFrame(t31_handle->channelNum, &rawFrame))
        {
            LOG("IMP_FrameSource_GetFrame(%d) failed", t31_handle->channelNum);
            return -EAGAIN;
        }
        if (frameDataBufferSize < rawFrame->size)
        {
            LOG("FrameDataBufferSize(%d) < frameSize(%d), frame dropped", frameDataBufferSize, rawFrame->size);
            ret = -ENOMEM;
        }
        else
        {
            memcpy(pFrameDataBuffer, (void *)rawFrame->virAddr, rawFrame->size);
            *pFrameSize = rawFrame->size;
            *pTimestamp = IMP_System_GetTimeStamp();
        }

        IMP_FrameSource_ReleaseFrame(t31_handle->channelNum, rawFrame);
    }
    else
    {
        size_t uPacketLen = 0;
        IMPEncoderStream encodeStream = {0};

        if (IMP_Encoder_PollingStream(t31_handle->channelNum, T31_POLLING_STREAM_TIMEOUT_MS))
        {
            LOG("IMP_Encoder_PollingStream(%d) timeout", t31_handle->channelNum);
            return -EAGAIN;
        }

        if (IMP_Encoder_GetStream(t31_handle->channelNum, &encodeStream, 1))
        {
            LOG("IMP_Encoder_GetStream(%d) failed", t31_handle->channelNum);
            return -EAGAIN;
        }

        for (int i = 0; i < encodeStream.packCount; i++)
        {
            uPacketLen += encodeStream.pack[i].length;
        }

        if (frameDataBufferSize < uPacketLen)
        {
            LOG("FrameDataBufferSize(%d) < frameSize(%d), frame dropped", frameDataBufferSize, uPacketLen);
            *pFrameSize = 0;
            ret = -ENOMEM;
        }
        else
        {
            size_t offset = 0;

            for (int i = 0; i < encodeStream.packCount; i++)
            {
                _get_packet(&encodeStream, &encodeStream.pack[i], pFrameDataBuffer + offset, uPacketLen - offset);
                offset += encodeStream.pack[i].length;
            }
            *pFrameSize = uPacketLen;
            *pTimestamp = IMP_System_GetTimeStamp();
        }

        // DLOGD("-------------------------------[pFrameSize] %d", *pFrameSize);
        IMP_Encoder_ReleaseStream(t31_handle->channelNum, &encodeStream);
    }

    return ret;
}

int bd_venc_release_stream(bd_venc_handle handle)
{
    T31_HANDLE_NULL_CHECK(handle);
    T31_HANDLE_GET(handle);

    if (_stop_recv_frame(handle, t31_handle->channelNum))
    {
        return -EAGAIN;
    }

    if (IMP_FrameSource_DisableChn(chn[t31_handle->channelNum].index))
    {
        LOG("FrameSource StreamOff failed");
        return -EAGAIN;
    }

    return _set_status(handle, BD_VENC_STATUS_STREAM_OFF);
}

void bd_venc_destroy(bd_venc_handle handle)
{
    if (!handle)
    {
        return;
    }
    T31_HANDLE_GET(handle);

    if (t31_handle->status == BD_VENC_STATUS_STREAM_ON)
    {
        bd_venc_release_stream(handle);
    }

    _set_status(handle, BD_VENC_STATUS_NOT_READY);

    if (chn[t31_handle->channelNum].enable)
    {
        if (t31_handle->format != VID_FMT_RAW)
        {
            if (IMP_System_UnBind(&chn[t31_handle->channelNum].framesource_chn, &chn[t31_handle->channelNum].imp_encoder))
            {
                LOG("UnBind FrameSource channel%d and Encoder failed", t31_handle->channelNum);
            }
            sample_encoder_exit();
        }

        /*Destroy channel */
        if (IMP_FrameSource_DestroyChn(chn[t31_handle->channelNum].index))
        {
            LOG("IMP_FrameSource_DestroyChn(%d) error", chn[t31_handle->channelNum].index);
        }
        chn[t31_handle->channelNum].enable = false;
    }

    ATOMIC_INT_SUB(&t31VideoSystemUser);

    if (!t31VideoSystemUser)
    {
        sample_system_exit();
    }

    free(handle);
}

void *bd_venc_send_packet(void *args)
{

    uint32_t retStatus = 0;

    bd_venc_handle venc_handle = (bd_venc_handle)args;
    void *buf = NULL;
    UINT64 timestamp = 0;
    SIZE_T frameSize = 0;


    buf = MEMALLOC(VIDEO_FRAME_BUFFER_SIZE_BYTES);

    CHK_ERR(buf != NULL, STATUS_NOT_ENOUGH_MEMORY, "[KVS Master] OOM when allocating buffer");
    CHK_ERR(venc_handle != NULL, STATUS_NULL_ARG, "[KVS Master] VideoCapturerHandle is NULL");
    CHK_ERR(bd_venc_enable_stream(venc_handle) == 0, STATUS_INVALID_OPERATION, "[KVS Master] Acquire video stream failed");

    int getFrameStatus = 0;
    while (1)
    {
        getFrameStatus = bd_venc_get_frame(venc_handle, buf, VIDEO_FRAME_BUFFER_SIZE_BYTES, &timestamp, &frameSize);
        switch (getFrameStatus)
        {
        case 0:
            bd_writeFrameToAllSessions(timestamp * HUNDREDS_OF_NANOS_IN_A_MICROSECOND, buf, frameSize, SAMPLE_VIDEO_TRACK_ID);
            break;
        case -EAGAIN:
            // frame is not ready yet
            BD_LOG_DEBUG("frame is not ready yet");
            usleep(1000);
            break;
        default:
            DLOGE("videoCapturerGetFrame failed");
        }
    }

CleanUp:
    DLOGI("[KVS Master] Closing video thread");

    bd_venc_release_stream(venc_handle);

    CHK_LOG_ERR(retStatus);

    MEMFREE(buf);
    buf = NULL;

    return (void *)retStatus;
}

bd_venc_handle g_venc_handle;

int bd_venc_init(){
    g_venc_handle = bd_venc_create();
    bd_venc_capability_t venc_capability = {0};
    bd_venc_get_capability(g_venc_handle, &venc_capability);
    bd_venc_set_config(g_venc_handle, VID_FMT_H264, VID_RES_1080P);
    return 0;
}
int bd_venc_start(){
    pthread_t id;
    pthread_create(&id, NULL, bd_venc_send_packet, (void*)g_venc_handle);
}
int bd_venc_stop(){}
int bd_venc_release(){}