
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <errno.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include "colorControl.h"

const char KEY_RED[] = "0000000000000001 00 KEY_RED";


int main(int argc, char *argv[])
{
    struct lirc_config *config;
    char *code;
    char *c;
    int ret;
    unsigned char redValue = 0;

    if( lirc_init("irexec",1) == -1)
        return 1;
    
    ledInit();

    while( lirc_nextcode(&code) == 0)
    {
        if (code == NULL) continue;
        printf("%s\n", code);
        if (strlen(KEY_RED) < strlen(code))
        code[strlen(KEY_RED)] = 0;
        if (!strcmp(code, KEY_RED))
        {
            redValue ^= 1;
            setLed(RED_LED, redValue);
        }
        free(code);
        if(ret==-1) break;
    }

    lirc_deinit();
    return 0;
}