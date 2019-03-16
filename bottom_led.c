#include "io_busy.h"
#include "bottom_led.h"

void setTimer(int seconds,int mseconds)
{
	struct timeval temp;
	temp.tv_sec = seconds;
	temp.tv_usec = mseconds;

	select(0,NULL,NULL,NULL,&temp);

	return ;
}

int set_led_mode(int mode)
{
	switch(mode){
		case 0:
			//等待联网状态，蓝灯依次点亮
			break;
		case 1:
			//联网中，【蓝色】呼吸灯
			break;
		case 2:
			//待机状态，底灯不亮
			break;
		case 3:
			//唤醒状态，蓝灯
			break;
		case 4:
			//休眠，一个橘黄色的灯亮
			
			break;
		case 5:
			//夜灯，底灯全亮，橘黄色，亮度可调节
			break;
		case 6:

			break;

		default:
			printf("This is not invalid mode!!!\n");



	}

	return 0;
}
