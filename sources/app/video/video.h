#ifndef __BD_VIDEO_H__
#define __BD_VIDEO_H__

#include <stdint.h>

typedef enum
{
	BD_VIDEO_CODEC_H264 = 0,
	BD_VIDEO_CODEC_H265,
	BD_VIDEO_CODEC_MJPEG,
} BD_VIDEO_CODEC_E;

typedef enum BD_VIDEO_FRAME_ID
{
	/* frame id h264 */
	BD_H264_FRAME_P = 0x21,
	BD_H264_FRAME_I = 0x25,
	BD_H264_FRAME_SPS = 0x27,
	BD_H264_FRAME_PPS = 0x28,

	/* frame id h265 */
	BD_H265_FRAME_P = 0x02,
	BD_H265_FRAME_I = 0x26,
	BD_H265_FRAME_VPS = 0x40,
	BD_H265_FRAME_SPS = 0x42,
	BD_H265_FRAME_PPS = 0x44
} BD_VIDEO_FRAME_ID_E;

typedef struct video
{
	uint8_t res;
	uint8_t fps;
	uint8_t codec;
} bd_video_config_t;

typedef void (*bd_video_recv_callback)(char *data, uint32_t len, uint64_t pts, uint8_t frame_type);
int bd_video_set_callback(uint8_t channel, bd_video_recv_callback callback);

int bd_video_set_config(int channel, bd_video_config_t *config);
int bd_video_get_config(int channel, bd_video_config_t *config);

#endif /* __BD_VIDEO_H__ */