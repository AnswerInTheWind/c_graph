#include <time.h>
#include <stdlib.h>

#include "component.h"

void rand_init()
{
	srand(time(NULL));
}

uint8_t	get_rand()
{
	return rand();
}