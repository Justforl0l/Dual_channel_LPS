/*
 * init.c
 *
 * Created: 06.08.2022 12:55:58
 *  Author: shama
 */ 

#include "../inc/init.h"

void mcu_init(void)
{
	adc_init();
	sei();
	lcd_init();
}

void adc_init(void)
{
	return;
}

void lcd_init(void)
{
	return;
}
