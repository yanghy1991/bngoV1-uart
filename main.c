#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include "ws2812.h"
#include "msq_send.h"
#include "bottom_led.h"
#include "ir_device.h"
//======================================  
struct msg_uart Messages = {0};
static pthread_t msq_thread; 
static pthread_t time_thread; 

int time_bright = 9;

void *msq_func(void *params)
{	
	while(1)
	{
		msq_recv(&Messages);
		//printf("Messages->flag:%d  text:%s \n",Messages.flag,Messages.text);
		if(Messages.flag == 3){
			if(!strcmp(Messages.text, "0"))
				time_bright = 0;
			else if(!strcmp(Messages.text, "1"))
				time_bright = 1;
			else if(!strcmp(Messages.text, "2"))
				time_bright = 2;
			else if(!strcmp(Messages.text, "3"))
				time_bright = 3;
			else if(!strcmp(Messages.text, "4"))
				time_bright = 4;
			else if(!strcmp(Messages.text, "5"))
				time_bright = 5;
			else if(!strcmp(Messages.text, "6"))
				time_bright = 6;
			else if(!strcmp(Messages.text, "7"))
				time_bright = 7;
			else if(!strcmp(Messages.text, "8"))
				time_bright = 8;
			else if(!strcmp(Messages.text, "9"))
				time_bright = 9;
			else if(!strcmp(Messages.text, "-1"))
				time_bright = -1;
			else 
				time_bright = 9;
			
			send_data_ws2812(time_bright);
		}
			

		usleep(100000);
	}

}

void *time_func(void *params)
{
	while(1)
	{
		send_data_ws2812(time_bright);
		sleep(10);
	}

}

int main(int argc, char *argv[])  
{  
	int ret;
    ProcessInit(); 
	msq_creat();
	
	ret = pthread_create(&msq_thread, NULL, msq_func, NULL);
	if (ret) {
		printf("create msq_thread error: %s\n", strerror(errno));
		return -1;
	}

	ret = pthread_create(&time_thread, NULL, time_func, NULL);
	if (ret) {
		printf("create time_thread error: %s\n", strerror(errno));
		return -2;
	}
	
	while (1)  
    {  
		//led
		sleep(20);
    }

	
	ProcessClose(); 
	msq_close();
	pthread_join(msq_thread, NULL);
	pthread_join(time_thread, NULL);
	
	return 0;
}  