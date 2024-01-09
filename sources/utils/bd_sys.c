#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "app.h"
#include "bd_log.h"

int bd_sys_cmd(char* format, ...) {  

    va_list args;
    char cmd[256];
    memset(cmd, 0, sizeof(cmd));

    va_start(args, format);
    vsnprintf(cmd, sizeof(cmd), format, args);
    va_end(args);

    BD_LOG_DEBUG("[%s]", cmd);
    return system(cmd);;
}