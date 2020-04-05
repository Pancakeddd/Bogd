#ifndef STATES_H_GUARD
#define STATES_H_GUARD

#include "worldtime.h"
#include "raylib.h"
#include "provinces.h"

struct worldtime_t;

#define REMOVE_STATE (Gamestate*)1

class Gamestate
{
public:
	Gamestate()
	{
	};

	virtual Gamestate *UpdateState();
	virtual void DrawState();
};

class MenuGamestate : public Gamestate
{
public:

	Gamestate *UpdateState();
	void DrawState();

private:
};

class MapGamestate : public Gamestate
{
public:
	MapGamestate()
	{
		prov_mng = ProvinceManager();
		cul_mng = CultureManager();
		//clock_ = WorldClock();
	}
	Gamestate *UpdateState();
	void DrawState();

	worldtime_t      clock_;
	CultureManager  cul_mng;
	ProvinceManager prov_mng;

private:
};

#endif