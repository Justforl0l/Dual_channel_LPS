/*
 * interrupts.c
 *
 * Created: 06.08.2022 17:54:28
 *  Author: shama
 */ 

#include "interrupts.h"

ISR(ADC_vect)
{
	if ((ADMUX & 0x0F) == 0)
	{
		channel_a.voltage_buffer += ADC;
		ADMUX = (ADMUX & 0xF0) | 1;
		channel_a.voltage_counter++;
	}
	else if ((ADMUX & 0x0F) == 1)
	{
		channel_a.current_buffer += ADC;
		ADMUX = (ADMUX & 0xF0) | 2;
		channel_a.current_counter++;
	}
	else if ((ADMUX & 0x0F) == 2)
	{
		channel_b.voltage_buffer += ADC;
		ADMUX = (ADMUX 0xF0) | 3;
		channel_b.voltage_counter++;
	}
	else if ((ADMUX & 0x0F) == 3)
	{
		channel_b.current_buffer += ADC;
		ADMUX = (ADMUX & 0xF0) | 0;
		channel_b.current_counter++;
	}
}
