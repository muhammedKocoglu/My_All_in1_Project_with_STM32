#include "TIMER.h"

void Timer_Init(void)
{
	GPIO_Init_Timer();
	//   F  =  Fosc/(Prescaler*ReloadRegister)
	
	//F=1 için (1 sn sayma için):
	TIM2->PSC = 80-1; 		//8Mhz divided by 800
	TIM2->ARR = 1000-1;	//8Mhz/8 divided by 1000
	
	TIM2->CNT = 0;
	TIM2->CR1 = 1;
	TIM2->DIER|=1;
}