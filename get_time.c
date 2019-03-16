#include "get_time.h"

void get_sys_date(char *d)
{
	//get system time
	time_t timep;
	time(&timep);
	struct tm *p;
	p = localtime(&timep);
	//memcpy(t,p,sizeof(struct tm));
	d[0] = p->tm_hour;
	d[1] = p->tm_min;
}

