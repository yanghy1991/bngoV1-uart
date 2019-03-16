#ifndef  _BOTTOM_LED_H_
#define  _BOTTOM_LED_H_
#include <sys/time.h>
#include <sys/select.h>
#include <time.h>

void setTimer(int seconds,int mseconds);

int set_led_mode(int mode);
#endif //_BOTTOM_LED_H_