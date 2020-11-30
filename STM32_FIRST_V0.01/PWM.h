#ifndef PWM_H
#define PWM_H

#include "SYSTEM.h"

// PWM - PA5

void PWM_Init(void);
void PWM_Start(void);
void PWM_Start_DC(uint16_t dc);

#endif
