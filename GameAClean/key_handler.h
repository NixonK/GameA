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
	// Map with keyboard button code as the key and
	// Unit8 state of the key (SDL_PRESSED or SDL_RELEASED)
	std::map<SDL_Keycode, Uint8> keyState;

public:
	/**
	* Constructor for key handling class; initialises keyState map as empty.
	*/
	KeyHandler();

	/**
	* Destructor for key handling class.
	*/
	~KeyHandler();

	/**
	* Loads image into the game renderer as a texture.
	*
	* @param event user caused event to be processed
	*/
	void LogEvent(SDL_Event event);
	bool IsPressed(SDL_Keycode keyCode);
	bool IsReleased(SDL_Keycode keyCode);
	void GiveInstructions(Player *player);
};

#endif