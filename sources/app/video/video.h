#ifndef __BD_VIDEO_H__
#define __BD_VIDEO_H__

#include <stdint.h>

#define SENSOR_NAME "gc2053"
#define SENSOR_CUBS_TYPE TX_SENSOR_CONTROL_INTERFACE_I2C
#define SENSOR_I2C_ADDR 0x37
#define SENSOR_WIDTH 1920
#define SENSOR_HEIGHT 1080
#define CHN0_EN 1
#define CHN1_EN 0
#define CHN2_EN 0
#define CHN3_EN 1
#define CROP_EN 1

#define BD_VIDEO_ENCODE_CHANNEL_NUM_MAX 2
typedef void (*bd_video_recv_callback)(uint8_t channel, char *data, uint32_t len, uint64_t pts, uint8_t frame_type);

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
	uint32_t width;
	uint32_t height;
	uint8_t fps;
	uint8_t codec;
	uint32_t gop;
	uint8_t bitrate_mode;
	uint32_t bitrate_num;
} bd_video_config_t;

typedef struct
{
	uint8_t state;
	uint8_t enable;
	uint8_t channel;

	pthread_t pid;
	pthread_mutex_t mutex;

	bd_video_recv_callback callback;
} bd_venc_context_t;

extern int IMP_OSD_SetPoolSize(int size);

int bd_isp_init();
int bd_video_init(int channel);
int bd_video_set_config(int channel, bd_video_config_t *config);
int bd_video_get_config(int channel, bd_video_config_t *config);

int bd_video_start(int channel);
int bd_video_stop(int channel);

#endif /* __BD_VIDEO_H__ */