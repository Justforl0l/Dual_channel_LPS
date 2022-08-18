/*
 * util.h
 *
 * Created: 06.08.2022 13:52:52
 *  Author: shama
 */ 


#ifndef BUTTON_UTIL_H_
#define BUTTON_UTIL_H_

#include <avr/io.h>
#include <stdbool.h>

#include "config.h"
#include "timer/timer_util.h"

typedef struct  
{
	bool is_pressed;
	bool current_state;
	bool debounced;
} Button_flags;

bool button_is_pressed(void);
void button_tick(void);

#endif /* BUTTON_UTIL_H_ */