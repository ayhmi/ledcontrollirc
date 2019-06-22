
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <errno.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lirc_client.h"


int main(int argc, char *argv[])
{
    struct lirc_config *config;
    char *code;
    char *c;
    int ret;

    if( lirc_init("irexec",1) == -1)
        exit EXIT_FAILURE;

    while( lirc_nextcode(&code) == 0)
    {
        if (code == NULL) continue;
        printf("%s\n", code);
        free(code);
        if(ret==-1) break;
    }

    lirc_deinit();
    exit(EXIT_SUCCESS);
}