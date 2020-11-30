#ifndef SYSTEM_H
#define SYSTEM_H

#include "stm32f3xx.h"                  // Device header

#define Led_Red					0x0010
#define Led_Green				0x0008
#define Buzzer					0x0020
#define Button_Left 		0x0001
#define Button_Right		0x0002
#define Button_OK				0x0004

#define anaMenu					0x0000
#define menu1						0x0001
#define menu2						0x0002
#define menu3						0x0003
#define menu4						0x0004


#define Buzzer_On()	do{GPIOB->BSRR |= Buzzer;}while(0)
#define Buzzer_Off() do{GPIOB->BSRR |= Buzzer << 16;}while(0)
#define Set_Green() do{GPIOB->BSRR |= Led_Green;}while(0)
#define Reset_Green() do{GPIOB->BSRR |= Led_Green << 16;}while(0)
#define Set_Red() do{GPIOB->BSRR |= Led_Red;}while(0)
#define Reset_Red() do{GPIOB->BSRR |= Led_Red;}while(0)

#define Button_Port GPIOB

extern unsigned char menu[5][5];
extern unsigned char _menu;
extern unsigned char select;

void GPIO_Init_PWM(void);
void GPIO_Init_LCD(void);
void GPIO_Init_ADC(void);
void systickDelayMs(int n);
void systickDelayUs(int n);
void GPIO_Init_USART(void);
void System_Init(void);
void GPIO_Init_Timer(void);

#endif
