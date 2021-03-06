// File:			main.cpp
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	The main file to execute the userinterface and game class.
//
// Notes:
//

#include "includes.h"
#include "user_interface.h"
#include "game.h"

int main(int argc, char * argv[]) {
	UserInterface mainUI;
	if (!(mainUI.Init()))
		return -1;

	Game mainGame(UserInterface::ScreenProperties::FPS);

	mainGame.Execute(mainUI.GetRenderer());

	return 0;
}