
#include "SYSTEM.h"
#include "LCD.h"
#include "ADC.h"
#include "PWM.h"
#include "UART.h"
#include "INTERRUPT.h"
#include "TIMER.h"


uint8_t menu[5][5] = {0,	0,	0,	0,	0,		//Ana Menu
											1,	59,	23,	31,	0,		//Tarih ve Saat
											2,	0,	30,	0,	0,		//Sicaklik
											3,	0,	0,	0,	0,		//Fan Modu
											4,	0,	0,	0,	0	};
//									Menu						 Geri
//									 No
uint8_t _menu=0;
uint8_t select=0;
											
int main(void){

	/*	Initializing	*/
	System_Init();
	LCD_Init();
	ADC_Init();
	PWM_Init();
	USART_Init();
	Timer_Init();
	Interrupt_Init();

	/*	------------	*/

	while(1)
	{
		LCD_Write_Menu();
		if(!(Button_Port->IDR & Button_Left))
		{
			if(select==menu[0][0])		
			{
				_menu--;
				if (_menu <=0) _menu=0;
			}
			
			if(select==menu[1][0])
			{
				_menu--;
				if (_menu <=0) _menu=0;
			}
			
		}
		if(!(Button_Port->IDR & Button_Right))
		{
			if(select==menu[0][0])		
			{
				_menu++;
				if (_menu >=4) _menu=4;
			}
			
			if(select==menu[1][0])
			{
			}
		
		}
		if(!(Button_Port->IDR & Button_OK))
		{
			if(select==menu[0][0])		
				{		select=_menu;
						_menu=0;			
				}
				
			if(select==menu[1][0])
			{
			}
			
		}

	}
	
	
}
