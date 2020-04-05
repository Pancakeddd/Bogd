#ifndef WORLDTIME_H_GUARD
#define WORLDTIME_H_GUARD

#include "states.h"

class Gamestate;

const unsigned int daysinmonths[12] = {
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

struct worldtime_t
{
	unsigned int year;
	unsigned int month;
	unsigned int day;

	void TickForward();
};

class WorldClock
{
public:
	WorldClock(worldtime_t time = {0, 0, 0})
	{
		now_ = time;
	}

	void Tick(Gamestate*);
	void AtMonthTick(Gamestate*);

	worldtime_t now_;
};

#endif