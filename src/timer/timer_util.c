/*
 * timer_util.c
 *
 * Created: 18.08.2022 19:08:12
 *  Author: shama
 */ 

#include "timer/timer_util.h"

volatile unsigned long TIMER_TICK = 0;

unsigned long timer_get_tick()
{
	return TIMER_TICK;
}
