#ifndef _WS2812_H_
#define _WS2812_H_
#include <unistd.h>

void ProcessInit();
void ProcessClose();
int send_data_ws2812(int mode);

#endif //_WS2812_H_