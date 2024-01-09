#include <stdio.h>
#include <stdint.h>
#include <errno.h>
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

int bd_video_set_callback(uint8_t channel, bd_video_recv_callback callback)
{
    int ret = IMP_Encoder_StartRecvPic(channel);
    while (1) /* get control module */
    {
        ret = IMP_Encoder_PollingStream(channel, 1000);
        if (ret < 0)
        {
            BD_LOG_ERROR("polling stream channel %d timeout", channel);
            continue;
        }
        IMPEncoderStream stream;
        ret = IMP_Encoder_GetStream(channel, &stream, 1);
        if (ret < 0)
        {
            BD_LOG_ERROR("get stream channel %d fail", channel);
            return BD_RET_VIDEO_GET_FAIL;
        }

        int i;
        int pack_nb = stream.packCount;
        printf("----------packCount=%d, seq=%u start----------\n", stream.packCount, stream.seq);
        for (i = 0; i < pack_nb; i++)
        {
            IMPEncoderPack pack = stream.pack[i];
            if (pack.length)
            {
                uint32_t pos = stream.streamSize - pack.offset;
                if (pos < pack.length)
                {
                    callback((char *)(stream.virAddr + pack.offset), pos, pack.timestamp, pack.nalType.h264NalType); /* test h264 */
                    callback((char *)stream.virAddr, pack.length - pos, pack.timestamp, pack.nalType.h264NalType);   /* test h264 */
                }
                else
                {
                    callback((char *)(stream.virAddr + pack.offset), pack.length, pack.timestamp, pack.nalType.h264NalType); /* test h264 */
                }
            }
        }
        printf("----------packCount=%d, stream->seq=%u end----------\n", stream.packCount, stream.seq);

        IMP_Encoder_ReleaseStream(channel, &stream);
    }
}

int bd_video_set_config(int channel, bd_video_config_t *config){
    int ret = BD_RET_OK;
    return ret;
}
int bd_video_get_config(int channel, bd_video_config_t *config){
    int ret = BD_RET_OK;
    return ret;
}