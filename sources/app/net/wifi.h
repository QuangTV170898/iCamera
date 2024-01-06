#ifndef __BD_NET_H__
#define __BD_NET_H__

#define BD_NET_WIFI_IF_STA_NAME "wlan0"
#define BD_NET_WIFI_IF_AP_NAME  "p2p0"

typedef struct
{
    char host_ip[16];
    char mac[18];
} bd_net_wifi_ip_t;

int bd_net_wifi_get_connect_info(const char *interface, bd_net_wifi_ip_t *info);

#endif /*__BD_NET_H__*/