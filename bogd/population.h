#pragma once

#include "culture.h"

class Population
{
public:
	Population(unsigned int pop, culture_t *culture)
	{
		pop_ = pop;
		culture_ = culture;
	}

	~Population()
	{
	}

	void AddPopulation(unsigned int);

	unsigned int pop_;
	culture_t *culture_;
};
