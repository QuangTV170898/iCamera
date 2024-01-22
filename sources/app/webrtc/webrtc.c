#include <stdio.h>
#include <stdbool.h>

#include "webrtc_common.h"
#include "bd_venc.h"

#define SERIAL_ID "t31"

extern PSampleConfiguration gSampleConfiguration;

int bd_initWebRTCKVS()
{
    return 0;
}
int bd_startWebRTCKVS()
{
    STATUS retStatus = STATUS_SUCCESS;
    PSampleConfiguration pSampleConfiguration = NULL;

    SET_INSTRUMENTED_ALLOCATORS();
    UINT32 logLevel = setLogLevel();

#ifndef _WIN32
    signal(SIGINT, sigintHandler);
#endif

    createSampleConfiguration(SERIAL_ID, SIGNALING_CHANNEL_ROLE_TYPE_MASTER, TRUE, TRUE, logLevel, &pSampleConfiguration);

    // Initialize KVS WebRTC. This must be done before anything else, and must only be done once.
    initKvsWebRtc();
    DLOGI("[KVS Master] KVS WebRTC initialization completed successfully");

    initSignaling(pSampleConfiguration, SAMPLE_MASTER_CLIENT_ID);

    return retStatus;
}

void bd_writeFrameToAllSessions(uint64_t timestamp, void *pData, uint64_t size, const char *const trackId)
{
    if (!gSampleConfiguration->connected)
        return;
    
    STATUS status = STATUS_SUCCESS;
    BOOL isVideo = TRUE;
    Frame frame = {
        .presentationTs = timestamp,
        .frameData = pData,
        .size = size,
    };

    if (!STRNCMP(trackId, SAMPLE_VIDEO_TRACK_ID, STRLEN(SAMPLE_VIDEO_TRACK_ID)))
    {
        isVideo = TRUE;
    }
    else if (!STRNCMP(trackId, SAMPLE_AUDIO_TRACK_ID, STRLEN(SAMPLE_AUDIO_TRACK_ID)))
    {
        isVideo = FALSE;
    }
    else
    {
        DLOGE("unknown trackId: %s", trackId);
        return;
    }

    MUTEX_LOCK(gSampleConfiguration->streamingSessionListReadLock);
    for (int i = 0; i < gSampleConfiguration->streamingSessionCount; ++i)
    {
        if (isVideo)
        {
            // DLOGD("------------------------ writeFrame %d ------------------------", size);
            status = writeFrame(gSampleConfiguration->sampleStreamingSessionList[i]->pVideoRtcRtpTransceiver, &frame);
        }
        else
        {
            status = writeFrame(gSampleConfiguration->sampleStreamingSessionList[i]->pAudioRtcRtpTransceiver, &frame);
        }
        if (status != STATUS_SRTP_NOT_READY_YET)
        {
            if (status != STATUS_SUCCESS)
            {
                DLOGV("writeFrame() failed with 0x%08x", status);
            }
            else if (gSampleConfiguration->sampleStreamingSessionList[i]->firstFrame && status == STATUS_SUCCESS)
            {
                PROFILE_WITH_START_TIME(gSampleConfiguration->sampleStreamingSessionList[i]->offerReceiveTime, "Time to first frame");
                gSampleConfiguration->sampleStreamingSessionList[i]->firstFrame = FALSE;
            }
        }
    }
    MUTEX_UNLOCK(gSampleConfiguration->streamingSessionListReadLock);
}
