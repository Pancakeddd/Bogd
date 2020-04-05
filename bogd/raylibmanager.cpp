#include "raylibmanager.h"


void RaylibManager::Init()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TOP_TITLE);
	SetTargetFPS(60);
}

Gamestate *RaylibManager::GetState()
{
	if (state_.size() > 0) {
		Gamestate *back = state_.back();
		return back;
	}
	return nullptr;
}

void RaylibManager::Draw()
{
	DrawCircleV(Vector2{ (float)sin(GetTime()*5)*100+500, (float)cos(GetTime() * 10) * 100+500 }, 50, MAROON);
	Gamestate * s = GetState();
	if (s != nullptr) {
		s->DrawState();
	}
}

void RaylibManager::Update()
{
	UpdateState();
}

void RaylibManager::UpdateState()
{
	Gamestate * s = GetState();
	if (s != nullptr) {
		Gamestate * new_s = s->UpdateState();
		if (new_s == REMOVE_STATE) {
			state_.pop_back();
		} else if (new_s != nullptr)
		{
			state_.push_back(new_s);
		}
		
	}
}

void RaylibManager::StartGame()
{
	while (!WindowShouldClose())
	{

		Update();

		BeginDrawing();

		ClearBackground(BLACK);

		Draw();

		EndDrawing();
	}
}