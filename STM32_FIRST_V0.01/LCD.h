#ifndef LCD_H
#define LCD_H

#include "SYSTEM.h"
/*-----CONNECTIONS-----
PC4-PC7: data lines
PB6: R/S
PB7: EN
GND: R/W
-----------------------*/

#define RS 0x40
#define EN 0x80


void LCD_nibble_write(char data, unsigned char control);
void systickDelayMs(int n);
void LCD_command(unsigned char command);
void LCD_data(char data);
void LCD_Init(void);
void LCD_write(const char *s);
void LCD_write_xy(char row,char pos,const char *msg);
void LCD_clear(void);
void LCD_Write_Menu(void);

#endif
