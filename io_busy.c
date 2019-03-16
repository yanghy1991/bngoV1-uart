#include "io_busy.h"

void gpio_init()
{
	echo_gpio_export(SYSFS_GPIO_A_PIN_VAL, sizeof(SYSFS_GPIO_A_PIN_VAL), SYSFS_GPIO_A_DIR);
	echo_gpio_export(SYSFS_GPIO_B_PIN_VAL, sizeof(SYSFS_GPIO_B_PIN_VAL), SYSFS_GPIO_B_DIR);
	echo_gpio_export(SYSFS_GPIO_C_PIN_VAL, sizeof(SYSFS_GPIO_C_PIN_VAL), SYSFS_GPIO_C_DIR);
	echo_gpio_export(SYSFS_GPIO_D_PIN_VAL, sizeof(SYSFS_GPIO_D_PIN_VAL), SYSFS_GPIO_D_DIR);
	echo_gpio_export(SYSFS_GPIO_E_PIN_VAL, sizeof(SYSFS_GPIO_E_PIN_VAL), SYSFS_GPIO_E_DIR);
	echo_gpio_export(SYSFS_GPIO_F_PIN_VAL, sizeof(SYSFS_GPIO_F_PIN_VAL), SYSFS_GPIO_F_DIR);
	echo_gpio_export(SYSFS_GPIO_G_PIN_VAL, sizeof(SYSFS_GPIO_G_PIN_VAL), SYSFS_GPIO_G_DIR);
	echo_gpio_export(SYSFS_GPIO_H_PIN_VAL, sizeof(SYSFS_GPIO_H_PIN_VAL), SYSFS_GPIO_H_DIR);
	echo_gpio_export(SYSFS_GPIO_D1_PIN_VAL,sizeof(SYSFS_GPIO_D1_PIN_VAL),SYSFS_GPIO_D1_DIR);
	echo_gpio_export(SYSFS_GPIO_D2_PIN_VAL,sizeof(SYSFS_GPIO_D2_PIN_VAL),SYSFS_GPIO_D2_DIR);
	echo_gpio_export(SYSFS_GPIO_D3_PIN_VAL,sizeof(SYSFS_GPIO_D3_PIN_VAL),SYSFS_GPIO_D3_DIR);
	echo_gpio_export(SYSFS_GPIO_D4_PIN_VAL,sizeof(SYSFS_GPIO_D4_PIN_VAL),SYSFS_GPIO_D4_DIR);
}

void gpio_exit()
{
	echo_gpio_unexport(SYSFS_GPIO_A_PIN_VAL, sizeof(SYSFS_GPIO_A_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_B_PIN_VAL, sizeof(SYSFS_GPIO_B_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_C_PIN_VAL, sizeof(SYSFS_GPIO_C_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_D_PIN_VAL, sizeof(SYSFS_GPIO_D_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_E_PIN_VAL, sizeof(SYSFS_GPIO_E_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_F_PIN_VAL, sizeof(SYSFS_GPIO_F_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_G_PIN_VAL, sizeof(SYSFS_GPIO_G_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_H_PIN_VAL, sizeof(SYSFS_GPIO_H_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_D1_PIN_VAL,sizeof(SYSFS_GPIO_D1_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_D2_PIN_VAL,sizeof(SYSFS_GPIO_D2_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_D3_PIN_VAL,sizeof(SYSFS_GPIO_D3_PIN_VAL));
	echo_gpio_unexport(SYSFS_GPIO_D4_PIN_VAL,sizeof(SYSFS_GPIO_D4_PIN_VAL));
}

int echo_gpio_export(char *pin_val,int p_count, char *dir_val)
{
 
	/* O_WRONLY O_RDONLY  O_RDWR
	 * echo 91 > export
	 */
	
	int fd;
	fd = open(SYSFS_GPIO_EXPORT, O_WRONLY);
	if(fd < 0){
		printf("echo_busy_export:open export error\n");
		return -1;	
	}

	write(fd, pin_val,p_count);
	close(fd);

	/*
	 *  /sys/class/gpio/gpio91# echo in > direction
	 */
	fd = open(dir_val, O_WRONLY);
	if(fd < 0){
		printf("echo_busy_export:busy pin direction open error\n");
		return -2;	
	}	

	write(fd, SYSFS_GPIO_SET_DIR_VAL, sizeof(SYSFS_GPIO_SET_DIR_VAL));
	close(fd);
	
    return 0;
}

int echo_gpio_unexport(char * pin_val,int p_count)
{
	int fd;
	fd = open(SYSFS_GPIO_UNEXPORT, O_WRONLY);
	if(fd < 0){
		printf("echo_busy_export:open export error\n");
		return -1;	
	}

	write(fd, pin_val,p_count);
	close(fd);

	return 0;
}


int set_gpio_val(char *g_val,const uint8 level)
{

	int fd,ret;
	fd = open(g_val, O_RDWR);
	if(fd < 0) {
		printf("set_gpio_val:%s open error.\n",g_val);
		return -1;
	}
	
	if(level == 0){
		ret = write(fd, "0",1);
		if(ret < 0)
			printf("set_gpio_val:write io L error! \n");
	}else if(level == 1){
		ret = write(fd, "1",1);
		if(ret < 0)
			printf("set_gpio_val:write io H error! \n");

	}
	close(fd);	
	return 0;
}



