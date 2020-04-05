#include "states.h"
#include <stdio.h>

Gamestate *Gamestate::UpdateState()
{
	return nullptr;
}

void Gamestate::DrawState()
{
}

// Menu Gamestate

Gamestate *MenuGamestate::UpdateState()
{
	if (IsKeyPressed(KEY_U))
	{
		MapGamestate *mapgamestate = new MapGamestate();

		Province *hattusa = new Province();
		
		hattusa->AddPopulation(new Population(100000, mapgamestate->cul_mng.GetCulture(culturetype_t::hittite)));
		
		
		mapgamestate->prov_mng.AddProvince(hattusa);

		return mapgamestate;
	}
	return nullptr;
}

void MenuGamestate::DrawState()
{
	DrawText("Bruh", 100, 200, 32, WHITE);
}

// Map Gamestate

Gamestate *MapGamestate::UpdateState()
{
	if (IsKeyPressed(KEY_U))
	{
		return REMOVE_STATE;
	}
	return nullptr;
}

void MapGamestate::DrawState()
{
	DrawText("Moment", 100, 200, 32, WHITE);
}