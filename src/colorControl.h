#ifndef COLORCONTROL_H
#define COLORCONTROL_H

#define RED_LED 0
#define GREEN_LED 1
#define BLUE_LED 2

void ledInit(void);
void setLed(unsigned int ledIndex, unsigned char value);

#endif



