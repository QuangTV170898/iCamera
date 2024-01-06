#include <stdio.h>

#include "app.h"
#include "wifi.h"
#include "bd_log.h"

#define APP_DEBUG 0

int bd_app_init(void)
{
    int ret = BD_RET_OK;
    BD_LOG_INFO("APP init");

#if APP_DEBUG
    bd_net_wifi_ip_t info;
    ret = bd_net_wifi_get_connect_info(BD_NET_WIFI_IF_STA_NAME, &info);
    if (ret != BD_RET_OK)
    {
        BD_LOG_ERROR("WIFI get connect info fail");
        return BD_RET_FAIL;
    }
    BD_LOG_INFO("IF: [%s] HOST: [%s] MAC: [%s]", BD_NET_WIFI_IF_STA_NAME, info.host_ip, info.mac);
#endif

    return ret;
}

void bd_app_release(void)
{
    BD_LOG_INFO("APP release");
}
