#ifndef _IO_BUSY_H_
#define _IO_BUSY_H_
#include <stdio.h>
#include <linux/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>

typedef unsigned char uint8;

#define SYSFS_GPIO_EXPORT          "/sys/class/gpio/export"
#define SYSFS_GPIO_UNEXPORT        "/sys/class/gpio/unexport"


#define SYSFS_GPIO_A_PIN_VAL   "7"
#define SYSFS_GPIO_B_PIN_VAL   "5"
#define SYSFS_GPIO_C_PIN_VAL   "2"
#define SYSFS_GPIO_D_PIN_VAL   "4"
#define SYSFS_GPIO_E_PIN_VAL   "49"
#define SYSFS_GPIO_F_PIN_VAL   "8"
#define SYSFS_GPIO_G_PIN_VAL   "3"
#define SYSFS_GPIO_H_PIN_VAL   "6"
#define SYSFS_GPIO_D1_PIN_VAL  "11"
#define SYSFS_GPIO_D2_PIN_VAL  "10"
#define SYSFS_GPIO_D3_PIN_VAL  "9"
#define SYSFS_GPIO_D4_PIN_VAL  "0"

#define SYSFS_GPIO_A_DIR       "/sys/class/gpio/gpio7/direction"
#define SYSFS_GPIO_B_DIR       "/sys/class/gpio/gpio5/direction"
#define SYSFS_GPIO_C_DIR       "/sys/class/gpio/gpio2/direction"
#define SYSFS_GPIO_D_DIR       "/sys/class/gpio/gpio4/direction"
#define SYSFS_GPIO_E_DIR       "/sys/class/gpio/gpio49/direction"
#define SYSFS_GPIO_F_DIR       "/sys/class/gpio/gpio8/direction"
#define SYSFS_GPIO_G_DIR       "/sys/class/gpio/gpio3/direction"
#define SYSFS_GPIO_H_DIR       "/sys/class/gpio/gpio6/direction"
#define SYSFS_GPIO_D1_DIR      "/sys/class/gpio/gpio11/direction"
#define SYSFS_GPIO_D2_DIR      "/sys/class/gpio/gpio10/direction"
#define SYSFS_GPIO_D3_DIR      "/sys/class/gpio/gpio9/direction"
#define SYSFS_GPIO_D4_DIR      "/sys/class/gpio/gpio0/direction"

#define SYSFS_GPIO_A_VAL       "/sys/devices/platform/leds-gpio/leds/digitalTupe_A/brightness"
#define SYSFS_GPIO_B_VAL       "/sys/devices/platform/leds-gpio/leds/digitalTupe_B/brightness"
#define SYSFS_GPIO_C_VAL       "/sys/devices/platform/leds-gpio/leds/digitalTupe_C/brightness"
#define SYSFS_GPIO_D_VAL       "/sys/devices/platform/leds-gpio/leds/digitalTupe_D/brightness"
#define SYSFS_GPIO_E_VAL       "/sys/devices/platform/leds-gpio/leds/digitalTupe_E/brightness"
#define SYSFS_GPIO_F_VAL       "/sys/devices/platform/leds-gpio/leds/digitalTupe_F/brightness"
#define SYSFS_GPIO_G_VAL       "/sys/devices/platform/leds-gpio/leds/digitalTupe_G/brightness"
#define SYSFS_GPIO_H_VAL       "/sys/devices/platform/leds-gpio/leds/digitalTupe_H/brightness"
#define SYSFS_GPIO_D1_VAL      "/sys/devices/platform/leds-gpio/leds/digitalTupe_D1/brightness"
#define SYSFS_GPIO_D2_VAL      "/sys/devices/platform/leds-gpio/leds/digitalTupe_D2/brightness"
#define SYSFS_GPIO_D3_VAL      "/sys/devices/platform/leds-gpio/leds/digitalTupe_D3/brightness"
#define SYSFS_GPIO_D4_VAL      "/sys/devices/platform/leds-gpio/leds/digitalTupe_D4/brightness"

#define SYSFS_GPIO_SET_DIR_VAL  "out"

#define SYSFS_GPIO_SET_VAL_H     "1"
#define SYSFS_GPIO_SET_VAL_L     "0"


void gpio_init();
void gpio_exit();


int echo_gpio_export(char *pin_val,int p_count,char *dir_val);
int echo_gpio_unexport(char *pin_val,int p_count);

int set_gpio_val(char *g_val,const unsigned char level);


#endif //_IO_BUSY_H_
