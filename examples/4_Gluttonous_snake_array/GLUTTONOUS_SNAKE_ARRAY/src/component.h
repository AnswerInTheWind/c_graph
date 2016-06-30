#ifndef COMPONENT_H
#define COMPONENT_H

#define uint32_t unsigned __int32
#define uint16_t unsigned __int16
#define uint8_t unsigned __int8

extern void rand_init();

extern uint8_t	get_rand();

extern void delay(uint32_t time_ms);

extern uint32_t timer_ms_get();
#endif