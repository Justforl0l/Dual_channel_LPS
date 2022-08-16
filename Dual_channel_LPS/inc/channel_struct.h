/*
 * channel_struct.h
 *
 * Created: 07.08.2022 12:09:01
 *  Author: shama
 */ 


#ifndef CHANNEL_STRUCT_H_
#define CHANNEL_STRUCT_H_

typedef struct
{
	unsigned int id;
	unsigned char voltage_counter;
	unsigned char current_counter;
	unsigned int voltage_value;
	unsigned int current_value;
	unsigned long voltage_buffer;
	unsigned long current_buffer;
} Channel;

#endif /* CHANNEL_STRUCT_H_ */