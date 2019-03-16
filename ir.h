#ifndef _IR_H_
#define _IR_H_
#include <ctype.h>

/* argv(HEX):[type][number][mode][key]
 * key:0x00 - 0x10
 */
extern int ir(unsigned char *argv);

extern void str_to_hex(const char *Src,unsigned char *Dest,int len);
extern int  check_argv1_invalid(const char *n);

/*
#define         KEY_OPEN                 0x00 
#define         KEY_CLOSE                0x01                    
#define 	    KEY_BACK                 0x02                   
#define         KEY_MENU                 0x03                   
#define         KEY_LEFT                 0x04                   
#define         KEY_RIGHT                0x05                    
#define         KEY_UP                   0x06                    
#define         KEY_DOWN                 0X07                 
#define         KEY_OK                   0x08                                      
#define         KEY_SEARCH               0x09                  
#define         KEY_GREEN                0x0a                   
#define         KEY_BLUE                 0x0b                   
#define         KEY_YELLOW               0x0c                                    
#define         KEY_PLAY                 0x0d                    
#define         KEY_VOLUMEUP             0x0e                   
#define         KEY_VOLUMEDOWN           0x0f                    
#define         KEY_HOME                 0x10                    
*/

#endif //_IR_H_