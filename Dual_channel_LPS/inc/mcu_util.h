/*
 * mcu_util.h
 *
 * Created: 06.08.2022 14:42:58
 *  Author: shama
 */ 


#ifndef MCU_UTIL_H_
#define MCU_UTIL_H_

#include <avr/io.h>

unsigned int voltage_calculation(void);
void voltage_display(unsigned int voltage);
unsigned int current_calculation(void);
void current_display(unsigned int current);

#endif /* MCU_UTIL_H_ */