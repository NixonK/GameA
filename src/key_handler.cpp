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

uMovementType KeyHandler::GetInstructions()
{
	uMovementType moveState = static_cast<uMovementType>(Movement::BLANK);
	if (IsPressed(SDLK_SPACE))
	{
		moveState |= Movement::JUMP;
	}
		

	if (IsPressed(SDLK_a) && IsPressed(SDLK_d))		// both a and d pressed
		moveState |= Movement::STOP;
	else if (IsPressed(SDLK_a))						// only a (left) pressed
		moveState |= Movement::LEFT;
	else if (IsPressed(SDLK_d))						// only d (right) pressed
		moveState |= Movement::RIGHT;
	else if (IsReleased(SDLK_a) && IsReleased(SDLK_d))	// both released
		moveState |= Movement::STOP;

	return moveState;
}
