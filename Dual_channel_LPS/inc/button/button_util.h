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

bool button_is_pressed(void);
void toggle_output_load(void);

#endif /* BUTTON_UTIL_H_ */