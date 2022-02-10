#include <iostream>
#include "TextScreen.h"
#include "Player.h"
#include "Monster.h"
#include <crtdbg.h>
#include "ConsoleGlobalInst.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
    
    MainScreen.SettingScreen();

    // けけけ
    // け【け
    // けけけ

    while (true)
    {
        if (true == IsExit)
        {
            return 0;
        }

        MainScreen.SettingScreen();
        MainPlayer.Render();
        // NewMonster.Render();
        MainScreen.PrintScreen();

        MainPlayer.Update();
        // NewMonster.Update();
    }
}