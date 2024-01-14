#include <stdio.h>
#include <app.h>
#include "bd_log.h"
#include "video.h"

int bd_app_init(void)
{
    int ret = BD_RET_OK;
    BD_LOG_INFO("APP init");

    bd_isp_init();

    bd_video_init(BD_VIDEO_MAIN_CHANNEL);
    bd_video_init(BD_VIDEO_SUB_CHANNEL);

    bd_video_config_t venc_main_conf;
    venc_main_conf.width = 1920;
    venc_main_conf.height = 1080;
    venc_main_conf.fps = 25;
    venc_main_conf.codec = BD_VIDEO_CODEC_H264;
    venc_main_conf.gop = 25;
    venc_main_conf.bitrate_mode = 1;
    venc_main_conf.bitrate_num = 1024;
    bd_video_set_config(BD_VIDEO_MAIN_CHANNEL, &venc_main_conf);

    bd_video_config_t venc_sub_conf;
    venc_sub_conf.width = 1280;
    venc_sub_conf.height = 720;
    venc_sub_conf.fps = 15;
    venc_sub_conf.codec = BD_VIDEO_CODEC_H264;
    venc_sub_conf.gop = 15;
    venc_sub_conf.bitrate_mode = 1;
    venc_sub_conf.bitrate_num = 1024;
    bd_video_set_config(BD_VIDEO_SUB_CHANNEL, &venc_sub_conf);

    bd_video_start(BD_VIDEO_MAIN_CHANNEL);
    bd_video_start(BD_VIDEO_SUB_CHANNEL);

    return ret;
}

void bd_app_release(void)
{
    BD_LOG_INFO("APP release");
    bd_video_stop(BD_VIDEO_MAIN_CHANNEL);
    bd_video_stop(BD_VIDEO_SUB_CHANNEL);
}
