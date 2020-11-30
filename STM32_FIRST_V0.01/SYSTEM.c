#include "SYSTEM.h"

void GPIO_Init_LCD(void)
{
	RCC->AHBENR |=0xC0000;		//Enable clock for PB and PC
	GPIOB->MODER |=0x0005000;	//PB6 and PB7 is output (Fixed)
	GPIOB->BSRR =0x00800000; 	//Clear EN
	
	GPIOC->MODER |= 0x05500;		
}

void GPIO_Init_USART(void)
{
	//Clock configurations for USART and TX	
	RCC->APB1ENR |=0x20000;
	RCC->AHBENR  |=0x20000;

	//AFR selection for PA2 and AFR mode selection for PA2
	GPIOA->AFR[0] |=0x7700;
	GPIOA->MODER |= 0xA0;
}
	
	
void GPIO_Init_ADC(void)
{
	RCC->CR |= 0x01000000;		//PLL
	RCC->CFGR2 |= 0x0100;
	RCC->AHBENR |=0x10000000;
	RCC->AHBENR |=0x00020000;
	GPIOA->MODER |=0xC0;
}

void GPIO_Init_PWM(void)
{
	RCC->APB1ENR |=0x01;
	RCC->AHBENR |=0x00020000;
	GPIOA->AFR[0] |=0x00100000;
	GPIOA->MODER |= 0x00000800;
}

void GPIO_Init_Timer(void)
{
	RCC-> APB1ENR |= 1;
}

	
void systickDelayMs(int n){
	SysTick->LOAD = 8000; 		//1ms
	SysTick->VAL |=0;					
	SysTick->CTRL|=5;					//0x00...0101; [2] CLCSOURCE 1=Processor clock; [1] TICKINT 0=No Interrupt ; [0] ENABLE 1=counter enable   
	
	for (int i=0;i<n;i++){
		while((SysTick->CTRL & 0x10000) ==0);
	}
	SysTick->CTRL=0;
}

void systickDelayUs(int n){
	SysTick->LOAD = 8; 		//1us
	SysTick->VAL |=0;					
	SysTick->CTRL|=5;					//0x00...0101; [2] CLCSOURCE 1=Processor clock; [1] TICKINT 0=No Interrupt ; [0] ENABLE 1=counter enable   
	
	for (int i=0;i<n;i++){
		while((SysTick->CTRL & 0x10000) ==0);
	}
	SysTick->CTRL=0;
}

void System_Init(void)
{
	RCC->AHBENR |= 0x040000;
	GPIOB->MODER &=~0x0FFF;
	GPIOB->MODER |= 0x0540;
}
