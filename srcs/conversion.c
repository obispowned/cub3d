#include "game.h"

float   radians_to_grads(float radians)
{
	return(radians * (180.0 / PI));
}

float   grads_to_radians(float grads)
{
	return(grads * (PI / 180.0));
}
