#include <stdio.h>
#include <app.h>
#include "bd_log.h"


int bd_app_init(void){
    int ret = BD_RET_OK;
    BD_LOG_INFO("APP init");
    return ret;
}

void bd_app_release(void){
    BD_LOG_INFO("APP release");
}

