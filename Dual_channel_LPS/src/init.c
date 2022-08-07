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
	_delay_ms(50);
	
	/* ���������������� ���������������� ������ */
	PORTD |= (1 << PD5);
	PORTD &= ~(1 << PD4);
	
	/* ��������� ���������������� ������ */
	PORTD |= (1 << EN);
	PORTD &= ~(1 << EN);
	_delay_ms(5);
	lcd_send_command(0x28);		/* ���� 4 ���, LCD - 2 ������ */
	lcd_send_command(0x08);		/* ������ ���������� ������� */
	lcd_send_command(0x01);		/* ������� ������� */
	_delay_us(100);
	lcd_send_command(0x06);		/* ����� ������� ������ */
	lcd_send_command(0x0C);		/* ��������� �������, ������ �� ����� */
}
