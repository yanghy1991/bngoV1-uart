#include "ir.h"
#include "ir_device.h"
#include <stdio.h>
#include <string.h>

int ir_control(char *ir_msg)
{
	unsigned char buf[5] = {0};
	char Device[20];
	char Brand[20];
	char Number[20];
	//char Mode[20] = {0};
	char Key[20];
	char *token;
	
	token = strtok(ir_msg,"-");
	int i = 1;
	   while( token != NULL )
	   {
	   		if(i ==1)
				strcpy(Device,token);
			else if(i ==2)
				strcpy(Brand,token);
			else if(i ==3)
				strcpy(Number,token);
			else if(i ==4)
				strcpy(Key,token);
		  ++i;
		  token = strtok( NULL,"-");
	   }
	//printf("%s %s %s %s\n",Device,Brand,Number,Key);

	if(strcmp(Device,"AIR") == 0){
		buf[0] = 0;
	} else {
		return -1;
	}
	
	if(strcmp(Number,"OPEN") == 0){
		buf[3] = 0;
	} else if(strcmp(Number,"CLOSE") == 0){
		buf[3] = 1;
	} else if(strcmp(Number,"UP") == 0){
		buf[3] = 4;
	} else if(strcmp(Number,"DOWN") == 0){
		buf[3] = 5;
	} 

	
	if(strcmp(Key,"16") == 0){
		buf[3] = 16;
	}else if(strcmp(Key,"17") == 0){
		buf[3] = 17;
	}else if(strcmp(Key,"18") == 0){
		buf[3] = 18;
	}else if(strcmp(Key,"19") == 0){
		buf[3] = 19;
	}else if(strcmp(Key,"20") == 0){
		buf[3] = 20;
	}else if(strcmp(Key,"21") == 0){
		buf[3] = 21;
	}else if(strcmp(Key,"22") == 0){
		buf[3] = 22;
	}else if(strcmp(Key,"23") == 0){
		buf[3] = 23;
	}else if(strcmp(Key,"24") == 0){
		buf[3] = 24;
	}else if(strcmp(Key,"25") == 0){
		buf[3] = 25;
	}else if(strcmp(Key,"26") == 0){
		buf[3] = 26;
	}else if(strcmp(Key,"27") == 0){
		buf[3] = 27;
	}else if(strcmp(Key,"28") == 0){
		buf[3] = 28;
	}else if(strcmp(Key,"29") == 0){
		buf[3] = 29;
	}else if(strcmp(Key,"30") == 0){
		buf[3] = 30;
	} 
	
	buf[4] = 1;
	/*
	for(i = 0;i<4;i++){
		printf("%02x",buf[i]);
	}
	printf("\n");
	*/
	if(ir(buf) != 0){
		printf("ir_device.c:ir_control errof!!!!!!\n");
		return -4;
	}
	
	return 0;
}
