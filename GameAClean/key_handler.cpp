// File:			key_handler.cpp
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	Handles and logs SDL_Event player key presses then passes
//				instructions to Player object.
//
// Notes:
//

#include "key_handler.h"

KeyHandler::KeyHandler()
{
	keyState = {};
}

KeyHandler::~KeyHandler()
{

}

void KeyHandler::LogEvent(SDL_Event event)
{
	keyState[event.key.keysym.sym] = event.key.state;
}

bool KeyHandler::IsPressed(SDL_Keycode keyCode)
{
	return (keyState[keyCode] == SDL_PRESSED);
}

bool KeyHandler::IsReleased(SDL_Keycode keyCode)
{
	return (keyState[keyCode] == SDL_RELEASED);
}

void KeyHandler::GiveInstructions(Player *player)
{
	if (IsPressed(SDLK_SPACE))
	{
		(*player).AttemptJump();
		//std::cout << "space pressed" << std::endl;
	}
		

	if (IsPressed(SDLK_a) && IsPressed(SDLK_d))		// both a and d pressed
		(*player).StopSprite();		
	else if (IsPressed(SDLK_a))						// only a (left) pressed
		(*player).MoveSprite('L');
	else if (IsPressed(SDLK_d))						// only d (right) pressed
		(*player).MoveSprite('R');
	else if (IsReleased(SDLK_a) && IsReleased(SDLK_d))	// both released
		(*player).StopSprite();
}
