#ifndef ADC_H
#define ADC_H
#include "stm32f3xx.h"                  // Device header

#include "SYSTEM.h"

// A1 = Analog

void ADC_Init(void);
void ADC_VoltReg_Enable(void);
void ADC_VoltReg_Disable(void);
void ADC_Calibration_Single(void);
void ADC_Enable(void);
void ADC_Disable(void);
uint16_t ADC_Read(void);

#endif
