#include "PWM.h"

void PWM_Init(void)
{
	GPIO_Init_PWM();
	TIM2->PSC = 10-1;
	TIM2->ARR = 26667-1;
	TIM2->CNT =0;
	TIM2->CCMR1=0x0060;  	//ENABLE PWM MODE
	TIM2->CCER=1;					//ENABLE PWM CH1
	TIM2->CCR1=2000-1;		//PULSE WIDTH 1/3 THE PERIOD
	
}
void PWM_Start(void)
{
	TIM2->CR1=1;
}

void PWM_Start_DC(uint16_t dc)
{
	TIM2->CCR1=dc;
	TIM2->CR1=1;
}
