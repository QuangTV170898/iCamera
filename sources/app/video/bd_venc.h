#ifndef __BD_VENC_H__
#define __BD_VENC_H__

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

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <stdint.h>

    typedef enum
    {
        VID_FMT_INVALID = 0,
        VID_FMT_H264,
        VID_FMT_H265,
        VID_FMT_VP8,
        VID_FMT_RAW,
    } BD_VENC_FMT_E;

    typedef enum
    {
        VID_RES_INVALID = 0,
        VID_RES_320P,
        VID_RES_360P,
        VID_RES_480P,
        VID_RES_720P,
        VID_RES_1080P,
        VID_RES_2K,
        VID_RES_4K,
    } BD_VENC_RESOLUTION_E;

    typedef enum
    {
        BD_VENC_STATUS_NOT_READY = 0,
        BD_VENC_STATUS_STREAM_OFF,
        BD_VENC_STATUS_STREAM_ON,
    } BD_VENC_STATUS_E;

    typedef struct
    {
        /*
         * ┌──────────────┐┌──────────────┐┌──────────────┐┌───────────────┐┌───────────────┐
         * │reserved[15-4]││VID_FMT_RAW[3]││VID_FMT_VP8[2]││VID_FMT_H265[1]││VID_FMT_H264[0]│
         * └──────────────┘└──────────────┘└──────────────┘└───────────────┘└───────────────┘
         */
        uint16_t formats;
        /*
         * ┌──────────────┐┌─────────────┐┌─────────────┐┌────────────────┐┌───────────────┐┌───────────────┐┌───────────────┐┌───────────────┐
         * │reserved[15-7]││VID_RES_4K[6]││VID_RES_2K[5]││VID_RES_1080P[4]││VID_RES_720P[3]││VID_RES_480P[2]││VID_RES_360P[1]││VID_RES_320P[0]│
         * └──────────────┘└─────────────┘└─────────────┘└────────────────┘└───────────────┘└───────────────┘└───────────────┘└───────────────┘
         */
        uint16_t resolutions;
    } bd_venc_capability_t;

    /**
     * @brief Handle of VideoCapturer.
     *
     */
    typedef void *bd_venc_handle;

    /**
     * @brief Create and init VideoCapturer.
     *
     * @return bd_venc_handle NULL or handle of created VideoCapturer.
     */
    bd_venc_handle bd_venc_create(void);

    /**
     * @brief Get capturer status.
     *
     * @param[in] handle Handle of VideoCapturer.
     * @return BD_VENC_STATUS_E Status of VideoCapturer.
     */
    BD_VENC_STATUS_E bd_venc_set_status(const bd_venc_handle handle);

    /**
     * @brief Get capturer capability.
     *
     * @param[in] handle Handle of VideoCapturer.
     * @param[out] pCapability Capturer capability.
     * @return int 0 or error code.
     */
    int bd_venc_get_capability(const bd_venc_handle handle, bd_venc_capability_t *pCapability);

    /**
     * @brief Set capturer format and resolution.
     *
     * @param[in] handle Handle of VideoCapturer.
     * @param[in] format Frame format.
     * @param[in] resolution Frame resolution.
     * @return int 0 or error code.
     */
    int bd_venc_set_config(bd_venc_handle handle, const BD_VENC_FMT_E format, const BD_VENC_RESOLUTION_E resolution);

    /**
     * @brief Get capturer format and resolution.
     *
     * @param[in] handle Handle of VideoCapturer.
     * @param[out] pFormat Frame format.
     * @param[out] pResolution Frame resolution.
     * @return int 0 or error code.
     */
    int bd_venc_get_config(const bd_venc_handle handle, BD_VENC_FMT_E *pFormat, BD_VENC_RESOLUTION_E *pResolution);

    /**
     * @brief Acquire and turn on video stream.
     *
     * @param[in] handle Handle of VideoCapturer.
     * @return int 0 or error code.
     */
    int bd_venc_enable_stream(bd_venc_handle handle);

    /**
     * @brief Blocking get frame from capturer.
     *
     * @param[in] handle Handle of VideoCapturer.
     * @param[in,out] pFrameDataBuffer Target frame data buffer.
     * @param[in] frameDataBufferSize Frame data buffer size.
     * @param[out] pTimestamp Frame timestamp in microseconds(usec).
     * @param[out] pFrameSize Frame data size in bytes.
     * @return int 0 or error code.
     */
    int bd_venc_get_frame(bd_venc_handle handle, void *pFrameDataBuffer, const size_t frameDataBufferSize, uint64_t *pTimestamp,
                          size_t *pFrameSize);

    /**
     * @brief Release acquired video stream.
     *
     * @param[in] handle Handle of VideoCapturer.
     * @return int 0 or error code.
     */
    int bd_venc_release_stream(bd_venc_handle handle);

    /**
     * @brief Destroy created VideoCapturer.
     *
     * @param[in] handle Handle of VideoCapturer.
     */
    void bd_venc_destroy(bd_venc_handle handle);

    int bd_venc_init();
    int bd_venc_start();

#ifdef __cplusplus
}
#endif

#endif /* __BD_VENC_H__ */