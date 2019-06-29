
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

const char KEY_RED[] = "00 KEY_YELLOW"; // couldn't configure red button
const char KEY_GREEN[] = "00 KEY_GREEN";
const char KEY_BLUE[] = "00 KEY_BLUE";


int main(int argc, char *argv[])
{
    struct lirc_config *config;
    char *code;
    char *c;
    int ret;
    unsigned char redValue = 0;
    unsigned char blueValue = 0;
    unsigned char greenValue = 0;

    if( lirc_init("irexec",1) == -1)
        return 1;
    
    ledInit();

    while( lirc_nextcode(&code) == 0)
    {
        if (code == NULL) continue;
        //printf("%s\n", code);
        if (strstr(code, KEY_RED))
        {
            redValue ^= 1;
            setLed(RED_LED, redValue);
        }
        if (strstr(code, KEY_BLUE))
        {
            blueValue ^= 1;
            setLed(BLUE_LED, blueValue);
        }
        if (strstr(code, KEY_GREEN))
        {
            greenValue ^= 1;
            setLed(GREEN_LED, greenValue);
        }
        free(code);
        if(ret==-1) break;
    }

    lirc_deinit();
    return 0;
}