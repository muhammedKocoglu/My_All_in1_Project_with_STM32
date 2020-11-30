#include "ADC.h"
#include "LCD.h"

void ADC_Init(void)
{
	GPIO_Init_ADC();
	ADC_VoltReg_Enable();
	ADC_Calibration_Single();
	ADC1->SQR1=0x80;
	ADC_Enable();
}

uint16_t ADC_Read(void)
{
	uint16_t analogValue;
	ADC1->CR |=0x04;
	while(!(ADC1->ISR & 0x04));
	analogValue=ADC1->DR;
	return analogValue;
}

void ADC_VoltReg_Enable(void)
{
	ADC1->CR = 0x00000000; 	
	systickDelayUs(20);
	ADC1->CR = 0x10000000;	
	systickDelayUs(20);
}

void ADC_VoltReg_Disable(void)
{
	ADC1->CR = 0x00000000;
	systickDelayUs(20);
	ADC1->CR = 0x20000000;
	systickDelayUs(20);
}

void ADC_Calibration_Single(void)
{
	ADC1->CR &=~0x40000000;
	ADC1->CR |= 0x80000000;
	while(ADC1->CR & 0x80000000);
}

void ADC_Enable(void)
{
	ADC1->CR |=0x01;
	while(!(ADC1->ISR & 0x01));
}

void ADC_Disable(void)
{
	while(ADC1->CR & 0x04 || ADC1->CR & 0x08);
	ADC1->CR |=0x02;
}


