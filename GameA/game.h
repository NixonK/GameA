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

#include "user_interface.h"
#include "key_handler.h"
#include "player.h"

class Game {
protected:
	// The status if the game is running.
	bool isRunning;

	// Event variable of keys.
	SDL_Event event;

	// KeyHandler class object.
	KeyHandler keyHandler;

	// Time in between frames.
	float FRAME_TIME;

	// Clock current milliseconds after starting the game
	float clock;

	// Difference in time.
	float deltaTime;

	// Delay inbetween renders.
	float renderDelay;

	// Player object.
	Player mainPlayer;

public:
	/**
	 * Game class constructor, initialise frame control variables and isRunning.
	 */
	Game(int fps);

	/**
	 * Game class destructor.
	 */
	~Game();

	/**
	 * Execute the game.
	 *
	 * @param SDLRenderer renderer to render everything onto.
	 */
	void Execute(SDL_Renderer *SDLRenderer);



	/**
	* Return the player object.
	*/
	Player *GetPlayer();
};

#endif