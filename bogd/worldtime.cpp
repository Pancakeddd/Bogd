#include "worldtime.h"
#include "states.h"

void worldtime_t::TickForward()
{
	if (++day > daysinmonths[month])
	{
		day = 1;
		if (++month > 12) {
			month = 0;
		}
	}
}

void WorldClock::Tick(Gamestate* g)
{
	now_.TickForward();
	if (now_.month == daysinmonths[now_.month])
	{
		AtMonthTick(g);
	}
}

void WorldClock::AtMonthTick(Gamestate* g)
{
	MapGamestate *g_map = (MapGamestate*)g;

	g_map->prov_mng.UpdateProvinces();
}