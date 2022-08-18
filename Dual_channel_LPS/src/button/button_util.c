/*
 * util.c
 *
 * Created: 06.08.2022 13:51:26
 *  Author: shama
 */ 

#include "button/button_util.h"

Button_flags _flags = {false, false, false};
unsigned int _button_timer = 0;

bool button_is_pressed(void)
{
	button_tick();
	return _flags.is_pressed;
}

void button_tick(void)
{
	_flags.current_state = (bool) (BUTTON_PORT & (1 << BUTTON_PIN)) >> BUTTON_PIN;
	
	if (_flags.current_state && !_flags.is_pressed)
	{
		if (_flags.debounced)
		{
			_flags.debounced = false;
			_button_timer = timer_get_tick();
		}
		else
		{
			if ((timer_get_tick() - _button_timer) >= BUTTON_DEBOUNCE_TIME)
			{
				_flags.is_pressed = true;
			}
		}
	}
	else
	{
		_flags.debounced = true;
		_flags.is_pressed = false;
	}
}
