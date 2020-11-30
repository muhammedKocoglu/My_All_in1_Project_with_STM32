#include "INTERRUPT.h"

char usart_int;
char timer_int;
void Interrupt_Init(void)
{
	__disable_irq();
	NVIC_EnableIRQ(USART2_IRQn);
	NVIC_EnableIRQ(TIM2_IRQn);
	__enable_irq();
}

void USART2_IRQHandler(void)
{
	char ch;
	static int i=0;
	if (i<10)
	{
		ch=USART2->RDR;
		usart_int=ch;
		i++;
	}
}

void TIM2_IRQHandler(void)
{	
	TIM2->SR=0;
	int i=1;
	GPIOA->ODR ^=0x20;
	timer_int+=i;

}