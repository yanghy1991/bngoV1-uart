#include "ws2812.h"
#include "SerDrive.h" 
#include "get_time.h"
#include <fcntl.h>      /*文件控制定义*/  
#include <stdio.h>  

int SerFd = -1; 
char data[3] = {0};

void ProcessInit()
{
    /* 
     * 打开USB转串口（ttyUSB0） 
     * O_RDWR 可读写设备 
     * O_NOCTTY 如果欲打开的文件为终端机设备时，则不会将该终端机当成进程控制终端机 
     * O_NDELAY 以不可阻断的方式打开文件，也就是无论有无数据读取或等待，都会立即返回进程之中 
     */  
    SerFd = open("/dev/ttyS1", O_RDWR|O_NOCTTY|O_NDELAY);  
    if (0 < SerFd)  
    {  
        set_opt(SerFd, BAUD_57600, DATA_BIT_8, PARITY_NONE, STOP_BIT_1);//设置串口参数  
    }  
    else  
    {  
        printf("open_port ERROR !\n"); 
    }

}

void ProcessClose()
{
	close(SerFd);
	SerFd = -1;
	
}


int send_data_ws2812(int mode)  
{  
	data[2] = mode;
	get_sys_date(data);

    if(send_data_tty(SerFd, data,sizeof(data)) != 0){
		usleep(100000);
		ProcessInit();
	}

	return 0;
} 





