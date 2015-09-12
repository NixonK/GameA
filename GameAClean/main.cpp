// File:			main.cpp
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	The main file to execute the userinterface and game class.
//
// Notes:
//

#include"includes.h"
#include"user_interface.h"
#include"game.h"

int main(int argc, char * argv[])
{
	UserInterface *mainUI = new UserInterface();
	if (!((*mainUI).Init()))
		return -1;

	Game *mainGame = new Game();

	(*mainGame).Execute((*mainUI).GetRenderer());

	//(*(*mainGame).GetPlayer()).CleanUp(); // player gets deleted on exit


	delete mainUI;
	mainUI = nullptr;
	delete mainGame;
	mainGame = nullptr;

	return 0;
}