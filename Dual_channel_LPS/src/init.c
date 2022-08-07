/*
 * init.c
 *
 * Created: 06.08.2022 12:55:58
 *  Author: shama
 */ 

#include "init.h"

void mcu_init(void)
{
	adc_init();
	sei();
	lcd_init();
}

void adc_init(void)
{
	ADMUX |= (1 << REFS1) | (1 << REFS0);
	ADCSRA |= (1 << ADEN) | (1 << ADSC) |
			  (1 << ADFR) | (1 << ADPS2) |
			  (1 << ADPS1) | (1 << ADIE);
}

void lcd_init(void)
{
	DDRD = 0xFF;
	PORTD = 0x00;
	_delay_ms(20);
	lcd_send_command((LCD_CMD_FUNCTION_SET | LCD_SETTING_DATA_LENGTH_8_BIT), _8_BIT_MODE);
	_delay_ms(5);
	lcd_send_command((LCD_CMD_FUNCTION_SET | LCD_SETTING_DATA_LENGTH_8_BIT), _8_BIT_MODE);
	_delay_us(110);
	lcd_send_command((LCD_CMD_FUNCTION_SET | LCD_SETTING_DATA_LENGTH_8_BIT), _8_BIT_MODE);
	
	lcd_send_command((LCD_CMD_FUNCTION_SET | LCD_SETTING_DATA_LENGTH_4_BIT), _8_BIT_MODE);
	/* TODO: «авершить код инициализации диспле€ */
}
