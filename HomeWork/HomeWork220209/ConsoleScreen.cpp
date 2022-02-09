#include <iostream>
#include "TextScreen.h"
#include "Player.h"
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	TextScreen NewScreen(10, 10, "¤±");
	NewScreen.SettingScreen();

	Player NewPlayer(&NewScreen, "¡Ù");

	while (true)
	{
		NewScreen.SettingScreen();
		NewPlayer.Render();
		NewScreen.PrintScreen();
		NewPlayer.Update();
	}
	
	int a = 10;
}