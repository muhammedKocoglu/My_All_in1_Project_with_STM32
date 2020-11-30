#ifndef UART_H
#define UART_H

#include "SYSTEM.h"

// PA2 - RX | PA3 - TX

void USART_Init(void);
int USART_write(int ch);
char USART_Read(void);



#endif
