#include <stdio.h>
#include <errno.h>

#include "app.h"
#include "bd_log.h"
#include "wifi.h"
#include "bd_sys.h"

#define BD_NET_WIFI_STA_WPA_FILE_NAME "/tmp/wpa_supplicant.conf"
#define BD_NET_WIFI_AP_HOSTAPD_FILE_NAME "/tmp/hostapd.conf"
#define BD_NET_WIFI_AP_UDHCPD_FILE_NAME "/tmp/udhcpd.conf"

#define BD_NET_WIFI_STA_SCAN_START_CMD "wpa_cli -i %s scan"
#define BD_NET_WIFI_STA_SCAN_RESULT_CMD "wpa_cli -i %s scan_result"
#define BD_NET_WIFI_STA_ADD_NETWORK_CMD "wpa_cli -i %s add_network"
#define BD_NET_WIFI_STA_SET_NETWORK_CMD "wpa_cli -i %s set_network %d \"%s\""
#define BD_NET_WIFI_STA_SELECT_NETWORK_CMD "wpa_cli -i %s select_network %d"
#define BD_NET_WIFI_STA_ENABLE_NETWORK_CMD "wpa_cli -i %s enable_network %d"
#define BD_NET_WIFI_STA_SAVE_CONFIG_CMD "wpa_cli -i %s save_config"
#define BD_NET_WIFI_STA_STATUS_CMD "wpa_cli -i %s status"

static int _net_wifi_sta_init();
static int _net_wifi_ap_init();

static int _net_wifi_scan_start();
static int _net_wifi_scan_result();

int bd_net_wifi_get_config()
{
    int ret = BD_RET_OK;
    return ret;
}

int bd_net_wifi_get_connect_info(const char *interface, bd_net_wifi_ip_t *info)
{
    int ret = BD_RET_OK;
    char cmd[128];
    char buf[32];
    sprintf((char *)cmd, BD_NET_WIFI_STA_STATUS_CMD, interface);
    FILE *f = popen((const char *)cmd, "r");
    if (f == NULL)
    {
        BD_LOG_ERROR("popen fail: %s", strerror(errno));
        return BD_RET_FAIL;
    }

    memset(buf, 0, sizeof(buf));
    memset(info, 0, sizeof(bd_net_wifi_ip_t));
    while (fgets(buf, sizeof(buf), f) != NULL)
    {
        sscanf((const char *)buf, "ip_address=%s", info->host_ip);
        sscanf((const char *)buf, "address=%s", info->mac);
    }

    pclose(f);
    return ret;
}

int bd_net_wifi_init(void)
{
    int ret = BD_RET_OK;
    ret = _net_wifi_ap_init();
    ret = _net_wifi_sta_init();
    return ret;
}

int bd_net_wifi_sta_scan_host_ap()
{
    int ret = BD_RET_OK;
    ret = _net_wifi_scan_start();
    ret = _net_wifi_scan_result();
    return ret;
}

int bd_net_wifi_sta_config_network()
{
    int ret = BD_RET_OK;
    return ret;
}

int bd_net_wifi_ap_config_network();

void bd_net_wifi_release()
{
    BD_LOG_INFO("WIFI module release");
}

static int _net_wifi_sta_init()
{
    int ret = BD_RET_OK;
    BD_LOG_INFO("WIFI sta init");

    ret = bd_sys_cmd("ifconfig %s up", BD_NET_WIFI_IF_STA_NAME);
    if (ret != BD_RET_OK)
    {
        BD_LOG_ERROR("WIFI sta init fail: up interface");
        return BD_RET_FAIL;
    }

    ret = bd_sys_cmd("echo ctrl_interface=/var/run/wpa_supplicant > %s", BD_NET_WIFI_STA_WPA_FILE_NAME);
    if (ret != BD_RET_OK)
    {
        BD_LOG_ERROR("WIFI sta init fail: ctrl_interface");
        return BD_RET_FAIL;
    }

    ret = bd_sys_cmd("echo update_config=1 >> %s", BD_NET_WIFI_STA_WPA_FILE_NAME);
    if (ret != BD_RET_OK)
    {
        BD_LOG_ERROR("WIFI sta init fail: update_config");
        return BD_RET_FAIL;
    }

    return ret;
}

static int _net_wifi_ap_init()
{
    int ret = BD_RET_OK;
    BD_LOG_INFO("WIFI ap init");

    char *ip = "192.168.39.1";
    ret = bd_sys_cmd("ifconfig %s %s up", BD_NET_WIFI_IF_AP_NAME, ip);
    if (ret != BD_RET_OK)
    {
        BD_LOG_ERROR("WIFI ap init fail: up interface");
        return BD_RET_FAIL;
    }

    ret = bd_sys_cmd("hostapd %s -B", BD_NET_WIFI_AP_HOSTAPD_FILE_NAME);
    if (ret != BD_RET_OK)
    {
        BD_LOG_ERROR("WIFI ap init fail: hostapd");
        return BD_RET_FAIL;
    }

    ret = bd_sys_cmd("udhcpd -f %s &", BD_NET_WIFI_AP_UDHCPD_FILE_NAME);
    if (ret != BD_RET_OK)
    {
        BD_LOG_ERROR("WIFI ap init fail: udhcpd");
        return BD_RET_FAIL;
    }
    return ret;
}

static int _net_wifi_scan_start()
{
    int ret = BD_RET_OK;
    BD_LOG_INFO("WIFI sta scan start");
    return ret;
}
static int _net_wifi_scan_result()
{
    int ret = BD_RET_OK;
    BD_LOG_INFO("WIFI sta scan result");
    return ret;
}