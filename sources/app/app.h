#ifndef __APP_H__
#define __APP_H__

#define BD_RET_OK 0
#define BD_RET_FAIL -1
#define BD_RET_VIDEO_GET_FAIL -2

#define BD_VIDEO_MAIN_CHANNEL   0
#define BD_VIDEO_SUB_CHANNLE    1

int bd_app_init(void);
void bd_app_release(void);

#endif /* __APP_H__ */