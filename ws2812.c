#include "ws2812.h"
#include "SerDrive.h" 
#include "get_time.h"
#include <fcntl.h>      /*�ļ����ƶ���*/  
#include <stdio.h>  

int SerFd = -1; 
char data[3] = {0};

void ProcessInit()
{
    /* 
     * ��USBת���ڣ�ttyUSB0�� 
     * O_RDWR �ɶ�д�豸 
     * O_NOCTTY ������򿪵��ļ�Ϊ�ն˻��豸ʱ���򲻻Ὣ���ն˻����ɽ��̿����ն˻� 
     * O_NDELAY �Բ�����ϵķ�ʽ���ļ���Ҳ���������������ݶ�ȡ��ȴ��������������ؽ���֮�� 
     */  
    SerFd = open("/dev/ttyS1", O_RDWR|O_NOCTTY|O_NDELAY);  
    if (0 < SerFd)  
    {  
        set_opt(SerFd, BAUD_57600, DATA_BIT_8, PARITY_NONE, STOP_BIT_1);//���ô��ڲ���  
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





