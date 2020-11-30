#include "UART.h"

// PA2 - USART

void USART_Init(void){	
	
	GPIO_Init_USART();
	//USART Baund Rate
	USART2->BRR |= 0x0341; //9600
	// baud rate= fclk/usartdiv (for oversampling=8)
	// OVER8(bit15 of cr1)=0 -> oversampling =8
	// fclk=8 mhz

	USART2->CR1 |= 0x0C;	//Enable Tx and USART
	USART2->CR1 |= 0x01;	//Enable Tx and USART
	USART2->CR1|=0x0020; 	//ENABLE RX INTERRUPT FOR USART2 
}

int USART_write(int ch){
	while(!(USART2->ISR & 0x0080)){}
	USART2->TDR =(ch & 0xFF);
	return ch;
}

char USART_Read(void){
	while(!(USART2->ISR & 0x0020));
	return USART2->RDR;
}
