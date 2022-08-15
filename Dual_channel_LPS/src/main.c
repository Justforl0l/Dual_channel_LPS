/*
 * main.c
 *
 * Created: 04.08.2022 20:25:05
 * Author : shama
 */ 

#include "main.h"

Channel channel_a = {1, 0, 0, 0, 0, 0, 0};
Channel channel_b = {1, 0, 0, 0, 0, 0, 0};

int main(void)
{
	Channel* output[] = {&channel_a, &channel_b};
	
	mcu_init();
	
    while (1) 
    {
		for (int i = 0; i < (sizeof(output)/sizeof(output[0])); i++)
		{
			if (output[i]->voltage_counter == 250)
			{
				voltage_calculation(output[i]);
				voltage_display(output[i]);
			}
			
			if (output[i]->current_counter == 250)
			{
				current_calculation(output[i]);
				current_display(output[i]);
			}
		}
		
		if (button_is_pressed())
		{
			toggle_output_load();
		}
    }
}
