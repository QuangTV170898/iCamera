#include <stdio.h>

#include "app.h"
#include "wifi.h"
#include "bd_log.h"

#define APP_DEBUG 1

int bd_app_init(void)
{
    int ret = BD_RET_OK;
    BD_LOG_INFO("APP init");

#if APP_DEBUG
    bd_net_wifi_sta_config_t sta_config;
    ret = bd_net_wifi_sta_get_config(&sta_config);
    if (ret)
    {

        ret = bd_net_wifi_sta_init();
        if (ret != BD_RET_OK)
            return BD_RET_FAIL;

        ret = bd_net_wifi_sta_set_config(&sta_config);
        if (ret != BD_RET_OK)
            return BD_RET_FAIL;

        ret = bd_net_wifi_sta_connect();
        if (ret != BD_RET_OK)
            return BD_RET_FAIL;
    }
    else
    {
        bd_net_wifi_ap_config_t ap_config;
        ret = bd_net_wifi_ap_set_config(&ap_config);
        if (ret != BD_RET_OK)
            return BD_RET_FAIL;

        ret = bd_net_wifi_ap_start();
        if (ret != BD_RET_OK)
            return BD_RET_FAIL;
    }

    // bd_net_wifi_ip_t info;
    // ret = bd_net_wifi_get_connect_info(BD_NET_WIFI_IF_STA_NAME, &info);
    // if (ret != BD_RET_OK)
    // {
    //     BD_LOG_ERROR("WIFI get connect info fail");
    //     return BD_RET_FAIL;
    // }
    // BD_LOG_INFO("IF: [%s] HOST: [%s] MAC: [%s]", BD_NET_WIFI_IF_STA_NAME, info.host_ip, info.mac);
#endif

    return ret;
}

void bd_app_release(void)
{
    BD_LOG_INFO("APP release");
}
