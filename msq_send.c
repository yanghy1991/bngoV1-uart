#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include "msq_send.h"
int msqid = -1;

int msq_creat()
{
	msqid = msgget(MSGUART,0666 | IPC_CREAT);
	if(msqid < 0){
		printf("msg queue creat failed [%d] [%s]\n",MSGUART,strerror(errno));
		return -1;
	}

	return 0;
}

int msq_recv(struct msg_uart *MessagesUart)
{
	long int msgtype = 0;

	if(msgrcv(msqid, (void*)MessagesUart, sizeof(struct msg_uart), msgtype, 0) == -1)
	{
		fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
		return -1;
	}

	return 0;
}

void msq_close()
{
	msgctl(msqid,IPC_RMID,0);
}
//消息队列，调节时钟和底灯的亮度
int msq_send(int flag,char *buf)
{
	struct msg_uart MessagesUart;
	int msgid = -1;
	//建立消息队列
	msgid = msgget((key_t)4782, 0666 | IPC_EXCL);
	if(msgid == -1)
	{
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		return -1;
	}

	MessagesUart.msg_type = 1;
	MessagesUart.flag = flag;
	strcpy(MessagesUart.text,buf);

	//向队列发送数据
	if(msgsnd(msgid,&MessagesUart,sizeof(struct msg_uart),0) == -1)
	{
		fprintf(stderr, "msgsnd failed\n");
		return -2;
	}

	return 0;
}
