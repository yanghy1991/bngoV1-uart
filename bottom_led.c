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
			//�ȴ�����״̬���������ε���
			break;
		case 1:
			//�����У�����ɫ��������
			break;
		case 2:
			//����״̬���׵Ʋ���
			break;
		case 3:
			//����״̬������
			break;
		case 4:
			//���ߣ�һ���ٻ�ɫ�ĵ���
			
			break;
		case 5:
			//ҹ�ƣ��׵�ȫ�����ٻ�ɫ�����ȿɵ���
			break;
		case 6:

			break;

		default:
			printf("This is not invalid mode!!!\n");



	}

	return 0;
}
