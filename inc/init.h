/*
 * init.h
 *
 * Created: 06.08.2022 12:55:48
 *  Author: shama
 */ 


#ifndef INIT_H_
#define INIT_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "lcd/lcd_util.h"
#include "lcd/lcd_commands.h"
#include "lcd/lcd_settings.h"
#include "config.h"
#include "lcd/custom_symbols/custom_symbols.h"

#include <util/delay.h>

void mcu_init(void);
void adc_init(void);
void timer_init(void);
void lcd_init(void);
void portb_init(void);

#endif /* INIT_H_ */