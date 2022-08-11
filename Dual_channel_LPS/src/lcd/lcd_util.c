/*
 * util.c
 *
 * Created: 06.08.2022 13:21:07
 *  Author: shama
 */ 

#include "lcd/lcd_util.h"

void lcd_send_command(unsigned char command, unsigned char mode,
					  unsigned char check_busy_flag)
{
	LCD_PORT &= ~((1 << RS) | (1 << RW));
	_delay_us(1);
	
	/* Старший нибл */
	LCD_PORT |= (1 << EN);
	LCD_PORT &= 0x0F;
	LCD_PORT |= (command & 0xF0);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	_delay_us(1);
	
	if (mode == _4_BIT_MODE)
	{
		/* Младший нибл */
		LCD_PORT |= (1 << EN);
		LCD_PORT &= 0x0F;
		LCD_PORT |= (command << 4);
		_delay_us(1);
		LCD_PORT &= ~(1 << EN);
		_delay_us(1);
	}
	if (check_busy_flag)
	{
		while (lcd_is_busy());
	}
}

void lcd_send_data(unsigned char data)
{
	LCD_PORT &= ~(1 << RW);
	LCD_PORT |= (1 << RS);
	_delay_us(1);
	
	/* Старший нибл */
	LCD_PORT |= (1 << EN);
	LCD_PORT &= 0x0F;
	LCD_PORT |= (data & 0xF0);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	_delay_us(1);
	
	/* Младший нибл */
	LCD_PORT |= (1 << EN);
	LCD_PORT &= 0x0F;
	LCD_PORT |= (data << 4);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	_delay_us(1);
}

void lcd_display_string(unsigned char command, char *string)
{
	return;
}

bool lcd_is_busy(void)
{
	unsigned char busy_flag = 0;
	LCD_PORT &= ~(1 << RS);
	LCD_PORT |= (1 << RW);
	_delay_us(1);
	LCD_PORT |= (1 << EN);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	busy_flag = (LCD_PORT >> 7);
	_delay_us(1);
	LCD_PORT |= (1 << EN);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN);
	_delay_us(1);
	
	return busy_flag;
}
