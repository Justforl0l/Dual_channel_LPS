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
		if (voltage_chA_counter == 250)
		{
			voltage_chA_value = voltage_chA_calculation();
			voltage_chA_display(voltage_chA_value);
		}
		
		if (current_chA_counter == 250)
		{
			current_chA_value = current_chA_calculation();
			current_chA_display(current_chA_value);
		}
		
		if (button_is_pressed())
		{
			toggle_output_load();
		}
    }
}
