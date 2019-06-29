#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <wiringPi.h>
#include "colorControl.h"

#define	NUM_LEDS	  3

int ledMap[NUM_LEDS] = { 12, 13, 14 };

void ledInit(void)
{
    int i;

    wiringPiSetup();
    
    for (i = 0; i < NUM_LEDS; ++i)
    {
        digitalWrite(ledMap[i], LOW);
        pinMode(ledMap[i], OUTPUT);
    }
}

void setLed(unsigned int ledIndex, unsigned char value)
{
    digitalWrite(ledMap[ledIndex], value);
}

