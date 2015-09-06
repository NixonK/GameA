// File:			game.h
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	Game class that runs at the constrained FPS variable speed to 
//				call the KeyHandler class and update Player movement. Finally, 
//				renders all updates at each frame tick.
//
// Notes:
//

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include"user_interface.h"
#include"key_handler.h"
#include"player.h"

class Game : public UserInterface
{
protected:
	bool isRunning;
	SDL_Event event;
	KeyHandler keyHandler;
	float FRAME_TIME;
	Uint32 clock;
	Uint32 deltaTime;
	Uint32 renderDelay;
	Player mainPlayer;
public:
	Game();
	void Execute(SDL_Renderer *SDLRenderer);
	Player *GetPlayer();
};

#endif