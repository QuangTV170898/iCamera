#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <errno.h>
#include <pthread.h>

#include <imp/imp_log.h>
#include <imp/imp_common.h>
#include <imp/imp_system.h>
#include <imp/imp_framesource.h>
#include <imp/imp_encoder.h>
#include <imp/imp_isp.h>
#include <imp/imp_osd.h>

#include "app.h"
#include "bd_log.h"
#include "video.h"

bd_venc_context_t context[BD_VIDEO_ENCODE_CHANNEL_NUM_MAX];

static void _record_sd(uint8_t channel, char *data, int size);
static void *video_callback(uint8_t channel, char *data, uint32_t len, uint64_t pts, uint8_t frame_type);
static void *_venc_get_frame(void *args);

int bd_isp_init()
{
    int ret = 0;
    IMPSensorInfo sensor_info;
    IMP_OSD_SetPoolSize(512 * 1024);

    memset(&sensor_info, 0, sizeof(IMPSensorInfo));
    memcpy(sensor_info.name, SENSOR_NAME, sizeof(SENSOR_NAME));
    sensor_info.cbus_type = SENSOR_CUBS_TYPE;
    memcpy(sensor_info.i2c.type, SENSOR_NAME, sizeof(SENSOR_NAME));
    sensor_info.i2c.addr = SENSOR_I2C_ADDR;

    BD_LOG_DEBUG("ISP init start");

    ret = IMP_ISP_Open();
    if (ret < 0)
    {
        BD_LOG_ERROR("failed to open ISP\n");
        return -1;
    }

    ret = IMP_ISP_AddSensor(&sensor_info);
    if (ret < 0)
    {
        BD_LOG_ERROR("failed to AddSensor\n");
        return -1;
    }

    ret = IMP_ISP_EnableSensor();
    if (ret < 0)
    {
        BD_LOG_ERROR("failed to EnableSensor\n");
        return -1;
    }

    ret = IMP_System_Init();
    if (ret < 0)
    {
        BD_LOG_ERROR("IMP_System_Init failed\n");
        return -1;
    }

    /* enable turning, to debug graphics */
    ret = IMP_ISP_EnableTuning();
    if (ret < 0)
    {
        BD_LOG_ERROR("IMP_ISP_EnableTuning failed\n");
        return -1;
    }
    IMP_ISP_Tuning_SetContrast(128);
    IMP_ISP_Tuning_SetSharpness(128);
    IMP_ISP_Tuning_SetSaturation(128);
    IMP_ISP_Tuning_SetBrightness(128);
#if 1
    ret = IMP_ISP_Tuning_SetISPRunningMode(IMPISP_RUNNING_MODE_DAY);
    if (ret < 0)
    {
        BD_LOG_ERROR("failed to set running mode\n");
        return -1;
    }
#endif
#if 0
    ret = IMP_ISP_Tuning_SetSensorFPS(SENSOR_FRAME_RATE_NUM, SENSOR_FRAME_RATE_DEN);
    if (ret < 0){
        BD_LOG_ERROR("failed to set sensor fps\n");
        return -1;
    }
#endif
    BD_LOG_DEBUG("ISP init done");

    return ret;
}

int bd_video_set_config(int channel, bd_video_config_t *config)
{
    int ret = BD_RET_OK;
    IMPEncoderProfile codec = IMP_ENC_PROFILE_AVC_BASELINE;
    IMPEncoderChnAttr venc_attr;
    IMPEncoderRcMode bitrate_mode = config->bitrate_mode;
    IMPFSChnAttr frs_attr = {
        .pixFmt = PIX_FMT_NV12,
        .nrVBs = 2,
        .type = FS_PHY_CHANNEL,

        .crop.enable = false,
        .crop.top = 0,
        .crop.left = 0,
        .crop.width = config->width,
        .crop.height = config->width,

        .scaler.enable = true,
        .scaler.outwidth = config->width,
        .scaler.outheight = config->height,

        .picWidth = config->width,
        .picHeight = config->height,

        .outFrmRateNum = config->fps,
        .outFrmRateDen = 1,
    };

    if (config->codec == BD_VIDEO_CODEC_H264)
    {
        codec = IMP_ENC_PROFILE_AVC_HIGH;
    }
    else if (config->codec == BD_VIDEO_CODEC_H265)
    {
        codec = IMP_ENC_PROFILE_HEVC_MAIN;
    }
    else if (config->codec == BD_VIDEO_CODEC_MJPEG)
    {
        codec = IMP_ENC_PROFILE_JPEG;
    }
    else
    {
    }

    IMPCell frs_cell = {
        .deviceID = DEV_ID_FS,
        .groupID = channel,
        .outputID = 0};

    IMPCell venc_cell = {
        .deviceID = DEV_ID_ENC,
        .groupID = channel,
        .outputID = 0};

    /* framesource init */
    IMP_FrameSource_CreateChn(channel, &frs_attr);
    IMP_FrameSource_SetChnAttr(channel, &frs_attr);

    /* encode init */
    IMP_Encoder_CreateGroup(channel);
    float ratio = 1;
    if (((uint64_t)frs_attr.picWidth * frs_attr.picHeight) > (1280 * 720))
    {
        ratio = log10f(((uint64_t)frs_attr.picWidth * frs_attr.picHeight) / (1280 * 720.0)) + 1;
    }
    else
    {
        ratio = 1.0 / (log10f((1280 * 720.0) / ((uint64_t)frs_attr.picWidth * frs_attr.picHeight)) + 1);
    }
    ratio = ratio > 0.1 ? ratio : 0.1;
    unsigned int uTargetBitRate = config->bitrate_num * ratio;
    /*
    uMaxSameSenceCnt la he so nhan cua GOP
    vd:
    - neu gop = fpt = 15 va uMaxSameSenceCnt=1 thi IFrame se xuat hien 1s 1 lan
    - neu gop = fpt = 15 va uMaxSameSenceCnt=2 thi IFrame se xuat hien 2s 1 lan
    */
    ret = IMP_Encoder_SetDefaultParam(&venc_attr, codec, bitrate_mode,
                                      frs_attr.picWidth, frs_attr.picHeight,
                                      frs_attr.outFrmRateNum, frs_attr.outFrmRateDen,
                                      config->gop, 1,
                                      (bitrate_mode == IMP_ENC_RC_MODE_FIXQP) ? 35 : -1,
                                      uTargetBitRate);

    IMP_Encoder_CreateChn(channel, &venc_attr);
    IMP_Encoder_RegisterChn(channel, channel);

    IMP_System_Bind(&frs_cell, &venc_cell);

    return ret;
}

int bd_video_get_config(int channel, bd_video_config_t *config)
{
    int ret = BD_RET_OK;
    return ret;
}

int bd_video_init(int channel)
{
    pthread_mutex_init(&context[channel].mutex, NULL);
    context[channel].channel = channel;
    context[channel].enable = false;
    context[channel].pid = 0;
    context[channel].state = 0;
    return 0;
}

int bd_video_start(int channel)
{
    IMP_FrameSource_EnableChn(channel);
    IMP_Encoder_StartRecvPic(channel);

    context[channel].channel = channel;
    context[channel].enable = true;
    context[channel].callback = (bd_video_recv_callback)video_callback;

    pthread_create(&context[channel].pid, NULL, _venc_get_frame, (void *)&context[channel]);
    return 0;
}

int bd_video_stop(int channel)
{
    int ret = 0;
    pthread_mutex_lock(&context[channel].mutex);
    context[channel].enable = false;
    BD_LOG_INFO("VENC stop channel %d", context[channel].channel);
    pthread_mutex_unlock(&context[channel].mutex);
    pthread_join(context[channel].pid, NULL);
    return ret;
}

static void _record_sd(uint8_t channel, char *data, int size)
{
    char path[32];
    sprintf(path, "%s/video.h26x.%d", "/media/video", channel);

    FILE *f = fopen(path, "a+");
    if (f == NULL)
    {
        return;
    }

    fwrite(data, size, 1, f);
    fclose(f);
}

static void *video_callback(uint8_t channel, char *data, uint32_t len, uint64_t pts, uint8_t frame_type)
{
    printf("channel: [%d] \tpts: [%lld] \tlen: [%d] \tdata: [%.2x]\n", channel, pts, len, data[4]);
    _record_sd(channel, data, len);
    return NULL;
}

static bool _venc_get_status(int channel)
{
    bool enable = false;
    pthread_mutex_lock(&context[channel].mutex);
    enable = context[channel].enable;
    pthread_mutex_unlock(&context[channel].mutex);
    return enable;
}

static void *_venc_get_frame(void *args)
{
    int ret = 0;

    bd_venc_context_t *context = (void *)args;

    BD_LOG_INFO("VENC get data channel %d", context->channel);

    while (_venc_get_status(context->channel))
    {
        ret = IMP_Encoder_PollingStream(context->channel, 1000);
        if (ret < 0)
        {
            BD_LOG_ERROR("polling stream channel %d timeout", context->channel);
            continue;
        }
        IMPEncoderStream stream;
        ret = IMP_Encoder_GetStream(context->channel, &stream, 1);
        if (ret < 0)
        {
            BD_LOG_ERROR("get stream channel %d fail", context->channel);
            return (void *)BD_RET_VIDEO_GET_FAIL;
        }

        int i;
        int pack_nb = stream.packCount;
        // printf("----------packCount=%d, seq=%u start----------\n", stream.packCount, stream.seq);
        for (i = 0; i < pack_nb; i++)
        {
            IMPEncoderPack pack = stream.pack[i];
            if (pack.length)
            {
                uint32_t pos = stream.streamSize - pack.offset;
                if (pos < pack.length)
                {
                    context->callback(context->channel, (char *)(stream.virAddr + pack.offset), pos, pack.timestamp, pack.nalType.h264NalType); /* test h264 */
                    context->callback(context->channel, (char *)stream.virAddr, pack.length - pos, pack.timestamp, pack.nalType.h264NalType);   /* test h264 */
                }
                else
                {
                    context->callback(context->channel, (char *)(stream.virAddr + pack.offset), pack.length, pack.timestamp, pack.nalType.h264NalType); /* test h264 */
                }
            }
        }
        // printf("----------packCount=%d, stream->seq=%u end----------\n", stream.packCount, stream.seq);

        IMP_Encoder_ReleaseStream(context->channel, &stream);
    }
    return NULL;
}