// File:			key_handler.h
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	Handles and logs SDL_Event player key presses then passes
//				instructions to Player object.
//
// Notes:
//

#ifndef KEY_HANDLER_H_INCLUDED
#define KEY_HANDLER_H_INCLUDED

#include"includes.h"
#include"player.h"
#include<map>


class KeyHandler
{
private:
	std::map<SDL_Keycode, Uint8> keyState;
public:
	KeyHandler();
	void LogEvent(SDL_Event event);
	bool IsPressed(SDL_Keycode keyCode);
	bool IsReleased(SDL_Keycode keyCode);
	void GiveInstructions(Player *player);
};

#endif