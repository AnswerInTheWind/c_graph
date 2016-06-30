#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "component.h"

void rand_init()
{
	srand(time(NULL));
}

uint8_t	get_rand()
{
	return rand();
}

void delay(uint32_t time_ms)
{
	Sleep(time_ms);
}

uint32_t timer_ms_get()
{
	return GetTickCount();
}