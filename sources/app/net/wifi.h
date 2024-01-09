#ifndef __BD_NET_H__
#define __BD_NET_H__

#define BD_NET_WIFI_IF_STA_NAME "wlan0"
#define BD_NET_WIFI_IF_AP_NAME  "p2p0"

typedef struct
{
    char host_ip[16];
    char mac[18];
} bd_net_wifi_ip_t;

typedef struct 
{
    char ssid[64];
    char pass[64];
} bd_net_wifi_sta_config_t;

typedef struct 
{
    char host_ip[16];
    char start_ip[16];
    char end_ip[16];
    char subnet[16];
    char ssid[64];
    char pass[64];
} bd_net_wifi_ap_config_t;


int bd_net_wifi_sta_init();
int bd_net_wifi_ap_start();

int bd_net_wifi_get_connect_info(const char *interface, bd_net_wifi_ip_t *info);

int bd_net_wifi_sta_get_config(bd_net_wifi_sta_config_t *config);
int bd_net_wifi_sta_set_config(bd_net_wifi_sta_config_t *config);
int bd_net_wifi_sta_connect();
int bd_net_wifi_sta_disconnect();

int bd_net_wifi_ap_set_config(bd_net_wifi_ap_config_t *config);

#endif /*__BD_NET_H__*/