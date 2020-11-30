#include "LCD.h"

void LCD_clear(void)
{
	LCD_command(0x01);
}

void LCD_write(const char *s)
{
    while(*s){
        LCD_data(*s++);
		}
}
void LCD_write_xy(char row,char pos,const char *msg)
{
    char location=0;
	
    if(row<=1)
    {
        location=(0x80) | ((pos) & 0x0f);  //Print message on 1st row and desired location
        LCD_command(location);
    }
    else
    {
        location=(0xC0) | ((pos) & 0x0f);  //Print message on 2nd row and desired location
        LCD_command(location);    
    }  
		LCD_write(msg);
}
		
void LCD_Init(void)
{
	GPIO_Init_LCD();
	//Init Sequence
	
	systickDelayMs(300);
	LCD_nibble_write(0x30,0);
	systickDelayMs(50);
	LCD_nibble_write(0x30,0);
	systickDelayMs(10);
  LCD_nibble_write(0x30,0);
	systickDelayMs(10);
	
	LCD_nibble_write(0x20,0); 		//set 4-bit data mode
	systickDelayMs(10);
	
	LCD_command(0x28);						//4-bit mode, 2-line, 5x7 font
	LCD_command(0x06);						//move cursor right
	LCD_command(0x01);						//clear screen, move cursor home
	LCD_command(0x0C);						//turn on display and blink cursor
}


void LCD_nibble_write(char data, unsigned char control)
{
	GPIOC->BSRR=0x00F00000; //Clear data
	GPIOC->BSRR =data & 0xF0;
	
	if(control & RS)
	{
		GPIOB->BSRR =RS;
	}
	else
	{
		GPIOB->BSRR= RS<<16;
	}
	//Pulse en
	GPIOB->BSRR =EN;
	systickDelayMs(0);
	GPIOB->BSRR =EN<<16;
}

void LCD_command(unsigned char command)
{
	LCD_nibble_write(command & 0xF0,0);		//upper 4 bits
	LCD_nibble_write(command<<4,0);				//lowe 4 bits
	
	if(command <4)
	{
		systickDelayMs(2);
	}
	else
		systickDelayMs(1);
}

void LCD_data(char data)
{
	LCD_nibble_write(data&0xF0, RS);
	LCD_nibble_write(data<<4,RS);
	systickDelayMs(1);
}

void LCD_Write_Menu(void)
{	
	switch(select)
	{
		case anaMenu:
			//
		LCD_write_xy(1,0,"ZAMAN VE SAAT");
		LCD_write_xy(2,0,"EVERTYHING IS OK");
		break;
		case menu1:
			//
		break;
		case menu2:
			//
		break;
		case menu3:
			//
		break;
		case menu4:
			//
		break;
		default: break;
	}
}
