#include "raylib.h"

#include "raylibmanager.h"

int main()
{
	MenuGamestate *gstate = new MenuGamestate();
	RaylibManager mng = RaylibManager(gstate);

	mng.Init();

	mng.StartGame();

	//delete gstate;

	return 0;
}