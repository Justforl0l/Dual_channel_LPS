/*
 * init.h
 *
 * Created: 06.08.2022 12:55:48
 *  Author: shama
 */ 


#ifndef INIT_H_
#define INIT_H_

#include <avr/io.h>

void mcu_init(void);
void adc_init(void);
void lcd_init(void);

#endif /* INIT_H_ */