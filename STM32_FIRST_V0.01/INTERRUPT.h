#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "SYSTEM.h"
#include "UART.h"

extern char timer_int;
extern char usart_int;
void Interrupt_Init(void);
void USART2_IRQHandler(void);
void TIM2_IRQHandler(void);

#endif
