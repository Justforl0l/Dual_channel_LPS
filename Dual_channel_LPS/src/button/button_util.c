/*
 * util.c
 *
 * Created: 06.08.2022 13:51:26
 *  Author: shama
 */ 

#include "button/button_util.h"

Button_flags _flags = {false, false, false};

bool button_is_pressed(void)
{
	button_tick();
	return _flags.is_pressed;
}

void button_tick(void)
{
	return;
}
