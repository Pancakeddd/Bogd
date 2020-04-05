#include "population.h"

void Population::AddPopulation(unsigned int x)
{
	if (pop_ + x > 0)
	{
		pop_ += x;
	}
}