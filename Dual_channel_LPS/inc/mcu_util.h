/*
 * mcu_util.h
 *
 * Created: 06.08.2022 14:42:58
 *  Author: shama
 */ 


#ifndef MCU_UTIL_H_
#define MCU_UTIL_H_

#include <avr/io.h>

unsigned int voltage_chA_calculation(void);
void voltage_chA_display(unsigned int voltage);
unsigned int current_chA_calculation(void);
void current_chA_display(unsigned int current);
void toggle_output_load(void);

#endif /* MCU_UTIL_H_ */