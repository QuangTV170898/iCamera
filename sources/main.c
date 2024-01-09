#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "app.h"
#include "bd_log.h"
#include "bd_sys.h"

static bool isFlag = true;
#define test    "~/workspace/"
void exit_handler()
{
    isFlag = false;
    bd_app_release();
}

int main()
{
    int ret = BD_RET_OK;

    signal(SIGINT, exit_handler);
    signal(SIGQUIT, exit_handler);
    signal(SIGTERM, exit_handler);
    signal(SIGKILL, exit_handler);

    ret = bd_app_init();
    if (ret != BD_RET_OK)
        exit(-1);
    ret = bd_sys_cmd("ls -la %s", test);
    if (ret != BD_RET_OK)
        exit(-1);

    while (isFlag)
    {
        usleep(1000);
    }
    return ret;
}