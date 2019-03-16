#include "SerDrive.h"  
#include <fcntl.h>      /*�ļ����ƶ���*/  
#include <stdio.h>  
//======================================  
int SerFd = -1;  
void ProcessInit(void)  
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
        set_opt(SerFd, BAUD_115200, DATA_BIT_8, PARITY_NONE, STOP_BIT_1);//���ô��ڲ���  
    }  
    else  
    {  
        printf("open_port ERROR !\n");  
    }  
}  
  
int main(int argc, char *argv[])  
{  
    int nTmp = 0;  
    //char Buf[1024];  
	char data[] = {0x12,0x34};
    ProcessInit();  
    send_data_tty(SerFd, data,sizeof(data));  
	//send_data_tty(SerFd, "hello series\n",sizeof("hello series\n")); 
    /*
	while (1)  
    {  
        //�Ӵ����ж�ȡ����  
        nTmp = read_datas_tty(SerFd, Buf, 100, 1024);  
        if(nTmp)printf("%s",Buf);  
        if (0 < nTmp)  
        {  
            //printf("rcv len=%d,data:%s\n",nTmp,Buf);  
            //�򴮿ڴ�����  
            send_data_tty(SerFd, Buf, nTmp);  
        }  
    }
	*/
	return 0;
}  