[root@WCV3:~]# /configs/startAPP.sh
Connecting to 192.168.1.104:8080 (192.168.1.104:8080)
iCamera               53% |****************               |  2430k  0:00:01 ETA[ 3007.665447] [atbm_log]:atbm_sdio_irq_period:Miss
iCamera              100% |*******************************|  4561k  0:00:00 ETA
22:39:58 INFO    app.c:11:      APP init
2024-01-22 15:39:58.237 INFO    initKvsWebRtc(): SDK version: 15e60193456709a3786f7c0f237c49ea7bd9c81f
2024-01-22 15:39:58.267 PROFILE createRtcCertificate(): [Certificate creation time] Time taken: 89 ms
2024-01-22 15:39:58.270 INFO    bd_startWebRTCKVS(): [KVS Master] KVS WebRTC initialization completed successfully
2024-01-22 15:39:58.271 INFO    createSignalingClientSync(): Creating Signaling Client Sync
2024-01-22 15:39:58.271 ERROR   signalingCacheLoadFromFile(): operation returned status code: 0x00000009
2024-01-22 15:39:58.271 WARN    createSignalingSync(): Failed to load signaling cache from file
[2024/01/22 22:39:58:2717] N: LWS: 4.2.1-v4.2.2, loglevel 7
[2024/01/22 22:39:58:2718] N: NET CLI H1 H2 WS MbedTLS ConMon IPv6-absent
[2024/01/22 22:39:58:2721] N:  ++ [wsi|0|pipe] (1)
[2024/01/22 22:39:58:2723] N:  ++ [vh|0|netlink] (1)
[2024/01/22 22:39:58:2725] N:  ++ [vh|1|default||-1] (2)
2024-01-22 15:39:58.273 PROFILE executeGetTokenSignalingState(): [Get token call] Time taken: 0 ms
2024-01-22 15:39:58.273 PROFILE createSignalingClientSync(): [Create signaling client] Time taken: 2 ms
2024-01-22 15:39:58.273 INFO    signalingClientFetchSync(): Signaling Client Fetch Sync
2024-01-22 15:39:58.273 INFO    describeChannel(): Calling because call is uncached
[2024/01/22 22:39:58:2743] N:  ++ [wsicli|0|POST/h1/kinesisvideo.us-east-1.amazonaws.com] (1)
2024-01-22 15:39:59.251 PROFILE createRtcCertificate(): [Certificate creation time] Time taken: 73 ms
2024-01-22 15:39:59.633 DEBUG   lwsHttpCallbackRoutine(): Client append handshake header

2024-01-22 15:39:59.633 DEBUG   lwsHttpCallbackRoutine(): Sending the body {
        "ChannelName": "t31"
}, size 25
2024-01-22 15:40:00.069 DEBUG   lwsHttpCallbackRoutine(): Connected with server response: 200
2024-01-22 15:40:00.069 DEBUG   lwsHttpCallbackRoutine(): Received client http
2024-01-22 15:40:00.069 DEBUG   lwsHttpCallbackRoutine(): Received client http read: 324 bytes
2024-01-22 15:40:00.069 DEBUG   lwsHttpCallbackRoutine(): Http client completed
2024-01-22 15:40:00.070 DEBUG   lwsHttpCallbackRoutine(): Client http closed
[2024/01/22 22:40:00:0704] N:  -- [wsicli|0|POST/h1/kinesisvideo.us-east-1.amazonaws.com] (0) 1.796s
2024-01-22 15:40:00.070 PROFILE executeDescribeSignalingState(): [Describe signaling call] Time taken: 1797 ms
[2024/01/22 22:40:00:0714] N:  ++ [wsicli|1|POST/h1/kinesisvideo.us-east-1.amazonaws.com] (1)
2024-01-22 15:40:00.236 PROFILE createRtcCertificate(): [Certificate creation time] Time taken: 58 ms
2024-01-22 15:40:01.407 DEBUG   lwsHttpCallbackRoutine(): Client append handshake header

2024-01-22 15:40:01.408 DEBUG   lwsHttpCallbackRoutine(): Sending the body {
        "ChannelARN": "arn:aws:kinesisvideo:us-east-1:810175132601:channel/t31/1705817789593",
        "SingleMasterChannelEndpointConfiguration": {
                "Protocols": ["WSS", "HTTPS"],
                "Role": "MASTER"
        }
}, size 193
2024-01-22 15:40:01.846 DEBUG   lwsHttpCallbackRoutine(): Connected with server response: 200
2024-01-22 15:40:01.846 DEBUG   lwsHttpCallbackRoutine(): Received client http
2024-01-22 15:40:01.846 DEBUG   lwsHttpCallbackRoutine(): Received client http read: 218 bytes
2024-01-22 15:40:01.846 DEBUG   lwsHttpCallbackRoutine(): Http client completed
2024-01-22 15:40:01.846 DEBUG   lwsHttpCallbackRoutine(): Client http closed
[2024/01/22 22:40:01:8473] N:  -- [wsicli|1|POST/h1/kinesisvideo.us-east-1.amazonaws.com] (0) 1.775s
2024-01-22 15:40:01.847 ERROR   signalingCacheSaveToFile(): operation returned status code: 0x00000009
2024-01-22 15:40:01.847 WARN    getChannelEndpoint(): Failed to save signaling cache to file
2024-01-22 15:40:01.847 PROFILE executeGetEndpointSignalingState(): [Get endpoint signaling call] Time taken: 1777 ms
[2024/01/22 22:40:01:8486] N:  ++ [wsicli|2|POST/h1/r-bd9d2fe4.kinesisvideo.us-east-1.amazonaws.] (1)
2024-01-22 15:40:02.810 DEBUG   lwsHttpCallbackRoutine(): Client append handshake header

2024-01-22 15:40:02.810 DEBUG   lwsHttpCallbackRoutine(): Sending the body {
        "ChannelARN": "arn:aws:kinesisvideo:us-east-1:810175132601:channel/t31/1705817789593",
        "ClientId": "ProducerMaster",
        "Service": "TURN"
}, size 141
2024-01-22 15:40:03.235 DEBUG   lwsHttpCallbackRoutine(): Connected with server response: 200
2024-01-22 15:40:03.235 DEBUG   lwsHttpCallbackRoutine(): Received client http
2024-01-22 15:40:03.235 DEBUG   lwsHttpCallbackRoutine(): Received client http read: 942 bytes
2024-01-22 15:40:03.236 DEBUG   lwsHttpCallbackRoutine(): Http client completed
2024-01-22 15:40:03.236 DEBUG   lwsHttpCallbackRoutine(): Client http closed
[2024/01/22 22:40:03:2366] N:  -- [wsicli|2|POST/h1/r-bd9d2fe4.kinesisvideo.us-east-1.amazonaws.] (0) 1.387s
2024-01-22 15:40:03.236 PROFILE executeGetIceConfigSignalingState(): [Get ICE config signaling call] Time taken: 1388 ms
2024-01-22 15:40:03.236 PROFILE signalingClientFetchSync(): [Fetch signaling client] Time taken: 4963 ms
[2024/01/22 22:40:03:2379] N:  ++ [wsicli|3|WS/h1/m-970102cb.kinesisvideo.us-east-1.amazonaws.co] (1)
2024-01-22 15:40:04.878 DEBUG   lwsWssCallbackRoutine(): Connection established
2024-01-22 15:4[ 3015.410118] set sensor gpio as PA-low-10bit
0:04.878 PROFILE executeConnectSignalingState(): [Connect signaling call] Time taken: 1641 ms
2024-01-22 15:40:04.878 PROFILE signalingClientConnectSync(): [Connect signaling client] Time taken: 1641 ms
2024-01-22 15:40:04.879 PROFILE initSignaling(): [Signaling Get token] 0 ms
2024-01-22 15:40:04.879 PROFILE initSignaling(): [Signaling Describe] 1797 ms
2024-01-22 15:40:04.879 PROFILE initSignaling(): [Signaling Create Channel] 0 ms
2024-01-22 15:40:04.879 PROFILE initSignaling(): [Signaling Get endpoint] 1777 ms
2024-01-22 15:40:04.879 PROFILE initSignaling(): [Signaling Get ICE config] 1388 ms
2024-01-22 15:40:04.879 PROFILE initSignaling(): [Signaling Connect] 1641 ms
2024-01-22 15:40:04.879 PROFILE initSignaling(): [Signaling create client] 2 ms
2024-01-22 15:40:04.879 PROFILE initSignaling(): [Signaling fetch client] 4963 ms
2024-01-22 15:40:04.879 PROFILE initSignaling(): [Signaling connect client][ 3015.496470] gc2053 chip found @ 0x37 (i2c0)
 1641 ms
---- FPGA board is ready ----
  Board UID : 30AB6E51
  Board HW ID : 72000460
  Board rev.  : 5DE5A975
  Board date  : 20190326
-----------------------------
VideoCapturer new status[1]
!! The specified ScalingList is not allowed; it will be adjusted!!
VideoCapturer new status[2]
IMP_Encoder_StartRecvPic(0)
2024-01-22 15:40:14.888 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:25.268 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.072 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:33.073 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.073 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:33.073 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:33.094 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:33.094 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.094 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:33.094 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:33.157 DEBUG   receiveLwsMessage(): Client received message of type: SDP_OFFER
2024-01-22 15:40:33.157 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.157 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:33.158 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_OFFER
2024-01-22 15:40:33.158 DEBUG   createSampleStreamingSession(): ======================================== [createSampleStreamingSession] ========================================
2024-01-22 15:40:33.158 DEBUG   initializePeerConnection(): ======================================== [initializePeerConnection initializePeerConnection] ========================================
2024-01-22 15:40:33.158 DEBUG   refreshIceConfiguration(): Refreshing the ICE Server Configuration
2024-01-22 15:40:33.158 DEBUG   refreshIceConfiguration(): Refreshing the ICE Server Configuration
2024-01-22 15:40:33.192 DEBUG   iceAgentValidateKvsRtcConfig():
        iceLocalCandidateGatheringTimeout: 10000 ms
        iceConnectionCheckTimeout: 0 ms
        iceCandidateNominationTimeout: 10000 ms
        iceConnectionCheckPollingInterval: 0 ms
2024-01-22 15:40:33.192 INFO    getIpWithHostName(): ICE SERVER Hostname received: stun.kinesisvideo.us-east-1.amazonaws.com
2024-01-22 15:40:33.192 WARN    getIpAddrFromDnsHostname(): Received unexpected hostname format: stun.kinesisvideo.us-east-1.amazonaws.com
2024-01-22 15:40:33.192 WARN    getIpWithHostName(): Parsing for address failed for stun.kinesisvideo.us-east-1.amazonaws.com, fallback to getaddrinfo
2024-01-22 15:40:33.211 PROFILE getIpWithHostName(): ICE Server address for stun.kinesisvideo.us-east-1.amazonaws.com with getaddrinfo: 3.217.8.220
2024-01-22 15:40:33.211 PROFILE createIceAgent(): [ICE server parsing] Time taken: 18 ms
2024-01-22 15:40:33.211 INFO    getIpWithHostName(): ICE SERVER Hostname received: 54.86.7.138
2024-01-22 15:40:33.211 PROFILE getIpWithHostName(): ICE Server address for 54.86.7.138: 54.86.7.138
2024-01-22 15:40:33.211 PROFILE createIceAgent(): [ICE server parsing] Time taken: 0 ms
2024-01-22 15:40:33.211 INFO    getIpWithHostName(): ICE SERVER Hostname received: 54.86.7.138
2024-01-22 15:40:33.211 PROFILE getIpWithHostName(): ICE Server address for 54.86.7.138: 54.86.7.138
2024-01-22 15:40:33.212 PROFILE createIceAgent(): [ICE server parsing] Time taken: 0 ms
2024-01-22 15:40:33.212 INFO    getIpWithHostName(): ICE SERVER Hostname received: 54.86.7.138
2024-01-22 15:40:33.212 PROFILE getIpWithHostName(): ICE Server address for 54.86.7.138: 54.86.7.138
2024-01-22 15:40:33.212 PROFILE createIceAgent(): [ICE server parsing] Time taken: 0 ms
2024-01-22 15:40:33.212 PROFILE createPeerConnection(): [Peer connection object creation time] Time taken: 53 ms
2024-01-22 15:40:33.213 INFO    handleOffer(): ============================== [handleOffer] ==============================
2024-01-22 15:40:33.220 DEBUG   iceAgentCheckConnectionStateSetup(): ice candidate pair count 0
2024-01-22 15:40:33.220 INFO    stepIceAgentStateMachine(): Ice agent state changed from ICE_AGENT_STATE_NEW to ICE_AGENT_STATE_CHECK_CONNECTION.
2024-01-22 15:40:33.221 INFO    onConnectionStateChange(): New connection state 2
2024-01-22 15:40:33.222 PROFILE iceAgentStartGathering(): [Host candidate gathering from local interfaces] Time taken: 0 ms
2024-01-22 15:40:33.222 DEBUG   createSocket(): setsockopt() NO_SIGNAL failed with errno Protocol not available
2024-01-22 15:40:33.222 PROFILE iceAgentStartGathering(): [Host candidates setup time] Time taken: 0 ms
2024-01-22 15:40:33.222 DEBUG   createSocket(): setsockopt() NO_SIGNAL failed with errno Protocol not available
2024-01-22 15:40:33.222 PROFILE iceAgentStartGathering(): [Srflx candidates setup time] Time taken: 0 ms
2024-01-22 15:40:33.223 DEBUG   createSocket(): setsockopt() NO_SIGNAL failed with errno Protocol not available
2024-01-22 15:40:33.223 DEBUG   createSocket(): setsockopt() NO_SIGNAL failed with errno Protocol not available
2024-01-22 15:40:33.224 PROFILE iceAgentStartGathering(): [Relay candidates setup time] Time taken: 1 ms
2024-01-22 15:40:33.226 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_NEW to TURN_STATE_CHECK_SOCKET_CONNECTION
2024-01-22 15:40:33.228 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_NEW to TURN_STATE_CHECK_SOCKET_CONNECTION
2024-01-22 15:40:33.228 DEBUG   iceAgentLogNewCandidate(): New local ice candidate discovered. Id: 7cvrw/rDM. Ip: 192.168.1.108:40452. Type: host. Protocol: udp.
2024-01-22 15:40:33.229 DEBUG   onIceCandidateHandler(): ======================================== [onIceCandidateHandler] ========================================
2024-01-22 15:40:33.229 DEBUG   sendLwsMessage(): Sending data over web socket: Message type: ICE_CANDIDATE, RecepientId: BTRX6GIWH4D
2024-01-22 15:40:33.559 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:33.559 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.560 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:33.560 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.561 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_CHECK_SOCKET_CONNECTION to TURN_STATE_GET_CREDENTIALS
2024-01-22 15:40:33.561 ERROR   turnConnectionStepState(): operation returned status code: 0x15000020
2024-01-22 15:40:33.561 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_CHECK_SOCKET_CONNECTION to TURN_STATE_FAILED
2024-01-22 15:40:33.562 DEBUG   sendLwsMessage(): Sending data over web socket: Message type: SDP_ANSWER, RecepientId: BTRX6GIWH4D
2024-01-22 15:40:33.562 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.563 PROFILE signalingSendMessageSync(): [Offer to answer time] Time taken: 405 ms
2024-01-22 15:40:33.564 PROFILE sendSignalingMessage(): [Signaling offer to answer] 405 ms
2024-01-22 15:40:33.564 ERROR   iceAgentAddRemoteCandidate(): operation returned status code: 0x5a000003
2024-01-22 15:40:33.564 ERROR   iceAgentAddRemoteCandidate(): operation returned status code: 0x5a000003
2024-01-22 15:40:33.564 INFO    mediaSenderRoutine(): ============================== [mediaSenderRoutine] ==============================
2024-01-22 15:40:33.564 INFO    mediaSenderRoutine(): ---------------------- waiting to connect -----------------------
2024-01-22 15:40:33.565 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:33.565 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:33.565 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: svrYj0Jpy. Ip: 171.248.188.106:50614. Type: srflx. Protocol: udp.
2024-01-22 15:40:33.565 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:33.565 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:33.566 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: l3UnUQcPv. Ip: 171.248.188.106:50612. Type: srflx. Protocol: udp.
2024-01-22 15:40:33.611 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM l3UnUQcPv, state: 1
2024-01-22 15:40:33.611 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM svrYj0Jpy, state: 1
2024-01-22 15:40:33.611 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:192.168.1.108, port:40452
2024-01-22 15:40:33.611 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:192.168.1.108, port:40452
2024-01-22 15:40:33.612 WARN    turnConnectionStepState(): TurnConnection in TURN_STATE_FAILED due to 0x15000020. Aborting TurnConnection
2024-01-22 15:40:33.612 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_FAILED to TURN_STATE_CLEAN_UP
2024-01-22 15:40:33.612 DEBUG   iceAgentLogNewCandidate(): New local ice candidate discovered. Id: 8QukcbXX0. Ip: 171.248.188.106:41477. Type: srflx. Protocol: udp.
2024-01-22 15:40:33.612 DEBUG   onIceCandidateHandler(): ======================================== [onIceCandidateHandler] ========================================
2024-01-22 15:40:33.613 DEBUG   sendLwsMessage(): Sending data over web socket: Message type: ICE_CANDIDATE, RecepientId: BTRX6GIWH4D
2024-01-22 15:40:33.613 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.661 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM l3UnUQcPv, state: 2
2024-01-22 15:40:33.661 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM svrYj0Jpy, state: 2
2024-01-22 15:40:33.661 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 svrYj0Jpy, state: 1
2024-01-22 15:40:33.661 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 l3UnUQcPv, state: 1
2024-01-22 15:40:33.662 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:192.168.1.108, port:40452
2024-01-22 15:40:33.662 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:192.168.1.108, port:40452
2024-01-22 15:40:33.663 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:171.248.188.106, port:41477
2024-01-22 15:40:33.663 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:171.248.188.106, port:41477
2024-01-22 15:40:33.664 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_CLEAN_UP to TURN_STATE_FAILED
2024-01-22 15:40:33.994 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM l3UnUQcPv, state: 2
2024-01-22 15:40:33.995 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM svrYj0Jpy, state: 2
2024-01-22 15:40:33.995 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 svrYj0Jpy, state: 2
2024-01-22 15:40:33.995 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 l3UnUQcPv, state: 2
2024-01-22 15:40:33.995 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:192.168.1.108, port:40452
2024-01-22 15:40:33.995 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:33.996 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.996 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:33.996 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.997 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:33.997 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:33.997 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:33.998 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:192.168.1.108, port:40452
2024-01-22 15:40:33.998 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:171.248.188.106, port:41477
2024-01-22 15:40:33.998 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:171.248.188.106, port:41477
2024-01-22 15:40:33.999 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_GET_CREDENTIALS to TURN_STATE_ALLOCATION
2024-01-22 15:40:33.999 WARN    turnConnectionStepState(): TurnConnection in TURN_STATE_FAILED due to 0x15000020. Aborting TurnConnection
2024-01-22 15:40:33.999 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:34.000 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:34.000 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:34.000 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: UbxVWjD/i. Ip: 54.224.119.115:53001. Type: relay. Protocol: udp.
2024-01-22 15:40:34.000 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:34.000 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:34.001 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: c9F7UujQA. Ip: 54.224.119.115:65487. Type: relay. Protocol: udp.
2024-01-22 15:40:34.001 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:34.001 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:34.001 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: JeFD0RrGj. Ip: 3.89.248.26:54273. Type: relay. Protocol: udp.
2024-01-22 15:40:34.001 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:34.002 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:34.002 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: a6H3as+3M. Ip: 3.89.248.26:59626. Type: relay. Protocol: udp.
2024-01-22 15:40:34.333 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM l3UnUQcPv, state: 2
2024-01-22 15:40:34.333 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM svrYj0Jpy, state: 2
2024-01-22 15:40:34.333 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 svrYj0Jpy, state: 2
2024-01-22 15:40:34.333 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 l3UnUQcPv, state: 2
2024-01-22 15:40:34.333 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM c9F7UujQA, state: 1
2024-01-22 15:40:34.333 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM UbxVWjD/i, state: 1
2024-01-22 15:40:34.334 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 c9F7UujQA, state: 1
2024-01-22 15:40:34.334 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 UbxVWjD/i, state: 1
2024-01-22 15:40:34.334 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM a6H3as+3M, state: 1
2024-01-22 15:40:34.334 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM JeFD0RrGj, state: 1
2024-01-22 15:40:34.334 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 a6H3as+3M, state: 1
2024-01-22 15:40:34.334 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 JeFD0RrGj, state: 1
2024-01-22 15:40:34.334 DEBUG   iceAgentCheckPeerReflexiveCandidate(): New remote peer reflexive candidate found
2024-01-22 15:40:34.334 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: hGMOtVd+z. Ip: 192.168.1.104:50612. Type: prflx. Protocol: UNKNOWN.
2024-01-22 15:40:34.335 DEBUG   handleStunPacket(): received candidate with USE_CANDIDATE flag, local candidate type host.
2024-01-22 15:40:34.335 DEBUG   iceCandidatePairCheckConnection(): remote ip:192.168.1.104, port:50612, local ip:192.168.1.108, port:40452
2024-01-22 15:40:34.335 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM hGMOtVd+z, state: 1
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 hGMOtVd+z, state: 1
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM l3UnUQcPv, state: 2
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM svrYj0Jpy, state: 2
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 svrYj0Jpy, state: 2
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 l3UnUQcPv, state: 2
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM c9F7UujQA, state: 1
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM UbxVWjD/i, state: 1
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 c9F7UujQA, state: 1
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 UbxVWjD/i, state: 1
2024-01-22 15:40:34.336 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM a6H3as+3M, state: 1
2024-01-22 15:40:34.337 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM JeFD0RrGj, state: 1
2024-01-22 15:40:34.337 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 a6H3as+3M, state: 1
2024-01-22 15:40:34.337 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 8QukcbXX0 JeFD0RrGj, state: 1
2024-01-22 15:40:34.337 DEBUG   iceCandidatePairCheckConnection(): remote ip:192.168.1.104, port:50612, local ip:192.168.1.108, port:40452
2024-01-22 15:40:34.337 DEBUG   iceCandidatePairCheckConnection(): remote ip:192.168.1.104, port:50612, local ip:171.248.188.106, port:41477
2024-01-22 15:40:34.338 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:192.168.1.108, port:40452
2024-01-22 15:40:34.672 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:192.168.1.108, port:40452
2024-01-22 15:40:34.672 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:171.248.188.106, port:41477
2024-01-22 15:40:34.673 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:171.248.188.106, port:41477
2024-01-22 15:40:34.673 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:65487, local ip:192.168.1.108, port:40452
2024-01-22 15:40:34.674 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:53001, local ip:192.168.1.108, port:40452
2024-01-22 15:40:34.674 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:65487, local ip:171.248.188.106, port:41477
2024-01-22 15:40:34.674 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:53001, local ip:171.248.188.106, port:41477
2024-01-22 15:40:34.675 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:59626, local ip:192.168.1.108, port:40452
2024-01-22 15:40:34.675 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:54273, local ip:192.168.1.108, port:40452
2024-01-22 15:40:34.676 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:59626, local ip:171.248.188.106, port:41477
2024-01-22 15:40:34.676 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:54273, local ip:171.248.188.106, port:41477
2024-01-22 15:40:34.676 DEBUG   handleStunPacket(): Pair succeeded! 7cvrw/rDM hGMOtVd+z
2024-01-22 15:40:34.677 DEBUG   handleStunPacket(): Ice candidate pair 7cvrw/rDM_hGMOtVd+z is connected. Round trip time: 341ms
2024-01-22 15:40:34.677 DEBUG   handleStunPacket(): Pair succeeded! 8QukcbXX0 hGMOtVd+z
2024-01-22 15:40:34.677 DEBUG   handleStunPacket(): Ice candidate pair 8QukcbXX0_hGMOtVd+z is connected. Round trip time: 340ms
2024-01-22 15:40:34.678 DEBUG   handleStunPacket(): received candidate with USE_CANDIDATE flag, local candidate type srflx.
2024-01-22 15:40:34.679 DEBUG   turnConnectionHandleStun(): TURN Allocation succeeded. Life time: 600 seconds. Allocation expiration epoch 170593863467899
2024-01-22 15:40:34.679 DEBUG   turnConnectionStepState(): Relay address received: 54.86.7.138, port: 63111
2024-01-22 15:40:34.679 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_ALLOCATION to TURN_STATE_CREATE_PERMISSION
2024-01-22 15:40:34.680 DEBUG   fromCheckConnectionIceAgentState(): Checking pair: 7cvrw/rDM hGMOtVd+z, state: 3
2024-01-22 15:40:34.680 INFO    stepIceAgentStateMachine(): Ice agent state changed from ICE_AGENT_STATE_CHECK_CONNECTION to ICE_AGENT_STATE_CONNECTED.
2024-01-22 15:40:34.681 INFO    iceAgentGatherCandidateTimerCallback(): Candidate gathering completed.
2024-01-22 15:40:34.681 DEBUG   iceAgentLogNewCandidate(): New local ice candidate discovered. Id: mKQ9vtS0T. Ip: 54.86.7.138:63111. Type: relay. Protocol: udp.
2024-01-22 15:40:34.681 DEBUG   onIceCandidateHandler(): ======================================== [onIceCandidateHandler] ========================================
2024-01-22 15:40:34.681 DEBUG   sendLwsMessage(): Sending data over web socket: Message type: ICE_CANDIDATE, RecepientId: BTRX6GIWH4D
2024-01-22 15:40:34.682 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:34.682 PROFILE iceAgentGatherCandidateTimerCallback(): [Candidate gathering time] Time taken: 1461 ms
2024-01-22 15:40:34.683 DEBUG   onIceCandidateHandler(): ======================================== [onIceCandidateHandler] ========================================
2024-01-22 15:40:34.683 DEBUG   onIceCandidateHandler(): ice candidate gathering finished
2024-01-22 15:40:34.725 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:34.726 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:34.726 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:34.726 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:34.726 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: aFlb8Xuek. Ip: 3.89.248.26:60280. Type: relay. Protocol: udp.
2024-01-22 15:40:35.057 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:35.057 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:35.057 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:35.058 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:35.058 DEBUG   turnConnectionHandleStun(): TURN Allocation succeeded. Life time: 599 seconds. Allocation expiration epoch 170593863401778
2024-01-22 15:40:35.058 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 171.248.188.106
2024-01-22 15:40:35.058 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 171.248.188.106
2024-01-22 15:40:35.059 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 54.224.119.115
2024-01-22 15:40:35.059 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 54.224.119.115
2024-01-22 15:40:35.059 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 3.89.248.26
2024-01-22 15:40:35.059 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 3.89.248.26
2024-01-22 15:40:35.060 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:192.168.1.108, port:40452
2024-01-22 15:40:35.060 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:192.168.1.108, port:40452
2024-01-22 15:40:35.061 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:171.248.188.106, port:41477
2024-01-22 15:40:35.061 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:171.248.188.106, port:41477
2024-01-22 15:40:35.062 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:35.062 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:35.063 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:35.063 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:65487, local ip:192.168.1.108, port:40452
2024-01-22 15:40:35.063 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:53001, local ip:192.168.1.108, port:40452
2024-01-22 15:40:35.064 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:65487, local ip:171.248.188.106, port:41477
2024-01-22 15:40:35.064 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:53001, local ip:171.248.188.106, port:41477
2024-01-22 15:40:35.065 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:35.065 DEBUG   receiveLwsMessage(): Client received message of type: ICE_CANDIDATE
2024-01-22 15:40:35.066 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:35.066 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:59626, local ip:192.168.1.108, port:40452
2024-01-22 15:40:35.069 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:54273, local ip:192.168.1.108, port:40452
2024-01-22 15:40:35.069 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:35.070 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:35.070 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:59626, local ip:171.248.188.106, port:41477
2024-01-22 15:40:35.070 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:35.071 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:35.403 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:54273, local ip:171.248.188.106, port:41477
2024-01-22 15:40:35.404 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:35.404 DEBUG   signalingMessageReceived(): ======================================== [signalingMessageReceived] ========================================
2024-01-22 15:40:35.404 DEBUG   iceCandidatePairCheckConnection(): remote ip:192.168.1.104, port:50612, local ip:54.86.7.138, port:63111
2024-01-22 15:40:35.404 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50614, local ip:54.86.7.138, port:63111
2024-01-22 15:40:35.404 DEBUG   iceCandidatePairCheckConnection(): remote ip:171.248.188.106, port:50612, local ip:54.86.7.138, port:63111
2024-01-22 15:40:35.405 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:53001, local ip:54.86.7.138, port:63111
2024-01-22 15:40:35.405 DEBUG   iceCandidatePairCheckConnection(): remote ip:54.224.119.115, port:65487, local ip:54.86.7.138, port:63111
2024-01-22 15:40:35.405 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:54273, local ip:54.86.7.138, port:63111
2024-01-22 15:40:35.405 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:59626, local ip:54.86.7.138, port:63111
2024-01-22 15:40:35.405 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:60280, local ip:192.168.1.108, port:40452
2024-01-22 15:40:35.406 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:60280, local ip:171.248.188.106, port:41477
2024-01-22 15:40:35.406 DEBUG   iceCandidatePairCheckConnection(): remote ip:3.89.248.26, port:60280, local ip:54.86.7.138, port:63111
2024-01-22 15:40:35.406 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: 8YHjWtaxv. Ip: 54.224.119.115:63000. Type: relay. Protocol: udp.
2024-01-22 15:40:35.407 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:35.407 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: brdFq4QkL. Ip: 3.89.248.26:54673. Type: relay. Protocol: udp.
2024-01-22 15:40:35.407 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:35.408 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: elOehCZ6v. Ip: 54.224.119.115:55815. Type: relay. Protocol: udp.
2024-01-22 15:40:35.408 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:35.408 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: yWqteM8Mt. Ip: 3.89.248.26:57402. Type: relay. Protocol: udp.
2024-01-22 15:40:35.409 DEBUG   signalingMessageReceived(): ------------------------------> SIGNALING_MESSAGE_TYPE_ICE_CANDIDATE
2024-01-22 15:40:35.409 DEBUG   iceAgentLogNewCandidate(): New remote ice candidate discovered. Id: /wovVdWkS. Ip: 3.89.248.26:65244. Type: relay. Protocol: udp.
2024-01-22 15:40:35.409 INFO    stepIceAgentStateMachine(): Ice agent state changed from ICE_AGENT_STATE_CONNECTED to ICE_AGENT_STATE_NOMINATING.
2024-01-22 15:40:35.411 PROFILE iceAgentReadyStateSetup(): Selected pair 7cvrw/rDM_hGMOtVd+z, local candidate type: host. remote candidate type: prflx. Round trip time 339 ms. Local candidate priority: 0, ice candidate pair priority: 384382795775
2024-01-22 15:40:35.411 DEBUG   iceAgentReadyStateSetup(): Freeing Turn allocations that are not selected. Total turn allocation count 2
2024-01-22 15:40:35.412 PROFILE executeReadyIceAgentState(): [Time taken to get ICE Agent ready for media exchange] Time taken: 2191 ms
2024-01-22 15:40:35.412 INFO    stepIceAgentStateMachine(): Ice agent state changed from ICE_AGENT_STATE_NOMINATING to ICE_AGENT_STATE_READY.
2024-01-22 15:40:35.745 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:40:35.748 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_CREATE_PERMISSION to TURN_STATE_CLEAN_UP
2024-01-22 15:40:35.748 DEBUG   turnConnectionHandleStun(): Channel bind succeeded with peer 171.248.188.106, port: 50614, channel number 16385
2024-01-22 15:40:35.749 DEBUG   turnConnectionHandleStun(): Channel bind succeeded with peer 171.248.188.106, port: 50612, channel number 16386
2024-01-22 15:40:35.750 DEBUG   turnConnectionHandleStun(): Channel bind succeeded with peer 54.224.119.115, port: 53001, channel number 16387
2024-01-22 15:40:35.750 DEBUG   turnConnectionHandleStun(): Channel bind succeeded with peer 54.224.119.115, port: 65487, channel number 16388
2024-01-22 15:40:35.750 DEBUG   turnConnectionHandleStun(): Channel bind succeeded with peer 3.89.248.26, port: 54273, channel number 16389
2024-01-22 15:40:35.750 DEBUG   turnConnectionHandleStun(): Channel bind succeeded with peer 3.89.248.26, port: 59626, channel number 16390
2024-01-22 15:40:35.750 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 3.89.248.26
2024-01-22 15:40:35.751 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 54.224.119.115
2024-01-22 15:40:35.751 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 3.89.248.26
2024-01-22 15:40:35.751 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 54.224.119.115
2024-01-22 15:40:35.751 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 3.89.248.26
2024-01-22 15:40:35.752 DEBUG   turnConnectionHandleStun(): create permission succeeded for peer 3.89.248.26
2024-01-22 15:40:36.021 PROFILE dtlsSessionChangeState(): [DTLS initialization completion] Time taken: 1340 ms
2024-01-22 15:40:36.023 PROFILE changePeerConnectionState(): [ICE Hole Punching Time] Time taken: 2801 ms
2024-01-22 15:40:36.023 INFO    onConnectionStateChange(): New connection state 3
2024-01-22 15:40:36.023 INFO    mediaSenderRoutine(): ---------------------- connected -----------------------
2024-01-22 15:40:36.023 DEBUG   rtcPeerConnectionGetMetrics(): ICE local candidate Stats requested at 17059380360236100
2024-01-22 15:40:36.023 DEBUG   logSelectedIceCandidatesInformation(): Local Candidate IP Address: 192.168.1.108
2024-01-22 15:40:36.023 DEBUG   logSelectedIceCandidatesInformation(): Local Candidate type: host
2024-01-22 15:40:36.023 DEBUG   logSelectedIceCandidatesInformation(): Local Candidate port: 40452
2024-01-22 15:40:36.024 DEBUG   logSelectedIceCandidatesInformation(): Local Candidate priority: 2130706431
2024-01-22 15:40:36.024 DEBUG   logSelectedIceCandidatesInformation(): Local Candidate transport protocol: udp
2024-01-22 15:40:36.024 DEBUG   logSelectedIceCandidatesInformation(): Local Candidate relay protocol: N/A
2024-01-22 15:40:36.024 DEBUG   logSelectedIceCandidatesInformation(): Local Candidate Ice server source: N/A
2024-01-22 15:40:36.024 DEBUG   rtcPeerConnectionGetMetrics(): ICE remote candidate Stats requested at 17059380360245113
2024-01-22 15:40:36.024 DEBUG   logSelectedIceCandidatesInformation(): Remote Candidate IP Address: 192.168.1.104
2024-01-22 15:40:36.024 DEBUG   logSelectedIceCandidatesInformation(): Remote Candidate type: prflx
2024-01-22 15:40:36.024 DEBUG   logSelectedIceCandidatesInformation(): Remote Candidate port: 50612
2024-01-22 15:40:36.024 DEBUG   logSelectedIceCandidatesInformation(): Remote Candidate priority: 1845501695
2024-01-22 15:40:36.024 DEBUG   logSelectedIceCandidatesInformation(): Remote Candidate transport protocol: udp
2024-01-22 15:40:36.037 PROFILE bd_writeFrameToAllSessions(): [Time to first frame] Time taken: 2879 ms
2024-01-22 15:40:36.087 DEBUG   turnConnectionHandleStun(): TURN Allocation freed.
2024-01-22 15:40:36.107 DEBUG   socketConnectionClosed(): Close socket 24
2024-01-22 15:40:36.107 DEBUG   turnConnectionStepState(): TurnConnection state changed from TURN_STATE_CLEAN_UP to TURN_STATE_NEW
2024-01-22 15:40:36.262 PROFILE createRtcCertificate(): [Certificate creation time] Time taken: 79 ms
2024-01-22 15:40:45.958 DEBUG   lwsWssCallbackRoutine(): Client is writable
[ 3057.935467] [atbm_log]:atbm_sdio_irq_period:Miss
2024-01-22 15:40:56.300 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:41:06.648 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:41:16.989 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:41:27.336 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:41:33.564 DEBUG   getIceCandidatePairStatsCallback(): Current duration: 60 seconds
2024-01-22 15:41:33.564 DEBUG   getIceCandidatePairStatsCallback(): Selected local candidate ID: 7cvrw/rDM
2024-01-22 15:41:33.564 DEBUG   getIceCandidatePairStatsCallback(): Selected remote candidate ID: hGMOtVd+z
2024-01-22 15:41:33.565 DEBUG   getIceCandidatePairStatsCallback(): Ice Candidate Pair state: 3
2024-01-22 15:41:33.565 DEBUG   getIceCandidatePairStatsCallback(): Nomination state: nominated
2024-01-22 15:41:33.565 DEBUG   getIceCandidatePairStatsCallback(): Packet send rate: 203.233333 pkts/sec
2024-01-22 15:41:33.565 DEBUG   getIceCandidatePairStatsCallback(): Packet receive rate: 0.000000 pkts/sec
2024-01-22 15:41:33.565 DEBUG   getIceCandidatePairStatsCallback(): Outgoing bit rate: 1793022.533333 bps
2024-01-22 15:41:33.565 DEBUG   getIceCandidatePairStatsCallback(): Incoming bit rate: 0.000000 bps
2024-01-22 15:41:33.565 DEBUG   getIceCandidatePairStatsCallback(): Packet discard rate: 0.000000 pkts/sec
2024-01-22 15:41:33.565 DEBUG   getIceCandidatePairStatsCallback(): Current STUN request round trip time: 0.339726 sec
2024-01-22 15:41:33.565 DEBUG   getIceCandidatePairStatsCallback(): Number of STUN responses received: 2
2024-01-22 15:41:37.733 DEBUG   lwsWssCallbackRoutine(): Client is writable
[ 3115.215475] [atbm_log]:atbm_sdio_irq_period:Miss
2024-01-22 15:41:48.072 DEBUG   lwsWssCallbackRoutine(): Client is writable
[ 3127.955501] [atbm_log]:atbm_sdio_irq_period:Miss
2024-01-22 15:41:58.406 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:42:08.748 DEBUG   lwsWssCallbackRoutine(): Client is writable
[ 3140.545459] [atbm_log]:atbm_sdio_irq_period:Miss
2024-01-22 15:42:16.436 DEBUG   dtlsSessionProcessPacket(): Detected DTLS close_notify alert
2024-01-22 15:42:16.437 INFO    onConnectionStateChange(): New connection state 6
2024-01-22 15:42:19.088 DEBUG   lwsWssCallbackRoutine(): Client is writable
2024-01-22 15:42:29.422 DEBUG   lwsWssCallbackRoutine(): Client is writable

# Signaling là gì?
# SDP là gì?
# ICE là gì?
# STUN server là gì?
# TURN server là gì?