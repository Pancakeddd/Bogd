#pragma once

#include "raylib.h"
#include "states.h"

#include <math.h>
#include <stdio.h>
#include <vector>

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define GAME_TOP_TITLE "bruh"

class RaylibManager
{
public:	
	RaylibManager(Gamestate *state)
	{
		state_.push_back(state);
	};
	~RaylibManager()
	{
		CloseWindow();

		for(Gamestate *state : state_)
		{
			delete state;
		}
	};

	void Init();
	Gamestate* GetState();

	void Draw();
	void Update();
	void UpdateState();

	void StartGame();

private:
	std::vector<Gamestate*> state_;
};

