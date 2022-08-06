/*
 * main.c
 *
 * Created: 04.08.2022 20:25:05
 * Author : shama
 */ 

#include "main.h"

int main(void)
{
	mcu_init();
	
    while (1) 
    {
		if (voltage_counter == 250)
		{
			voltage_value = voltage_calculation();
			voltage_display(voltage_value);
		}
		
		if (current_counter == 250)
		{
			current_value = current_calculation();
			current_display(current_value);
		}
		
		if (button_is_pressed())
		{
			toggle_output_load();
		}
    }
}
