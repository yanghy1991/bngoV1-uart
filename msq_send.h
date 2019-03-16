#ifndef _MSQ_SEND_H_
#define _MSQ_SEND_H_

#define MSGUART 4782

struct msg_uart
{
	long int msg_type;
	int flag;
	char text[4096];
};

int msq_creat();
void msq_close();
int msq_recv(struct msg_uart *MessagesUart);
int msq_send(int flag,char *buf);


#endif //_MSQ_SEND_H_