#ifndef __WEBRTC_H__
#define __WEBRTC_H__

#include <stdint.h>
int bd_initWebRTCKVS();
int bd_startWebRTCKVS();
void bd_writeFrameToAllSessions(uint64_t timestamp, void *pData, uint64_t size, const char *const trackId);

#endif /* __WEBRTC_H__*/