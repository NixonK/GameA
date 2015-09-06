// File:			game.cpp
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	Game class that runs at the constrained FPS variable speed to 
//				call the KeyHandler class and update Player movement. Finally, 
//				renders all updates at each frame tick.
//
// Notes:
//

#include "game.h"

Game::Game()
{
	isRunning = true;
	//SDL_Event event;
	//KeyHandler keyHandler;
	// float FPS = 60;
	FRAME_TIME = (1.0f / FPS) * 1000.0f;  // milliseconds per frame
	clock = 0;
	deltaTime = 0;
	renderDelay = 0;
	Player *mainPlayer;
}

Player *Game::GetPlayer()
{
	return &mainPlayer;
}

void Game::Execute(SDL_Renderer *SDLRenderer)
{

	// Select the color for drawing. It is set to red here.
	SDL_SetRenderDrawColor(SDLRenderer, 255, 75, 75, 255);
	// Clear the entire screen to our selected color.
	SDL_RenderClear(SDLRenderer);
	// Up until now everything was drawn behind the scenes.
	// This will show the new, red contents of the window.
	SDL_RenderPresent(SDLRenderer);


	mainPlayer.LoadSpriteTexture(SDLRenderer);

	//SDL_Texture *spriteSheet = LoadTexture("sprite.bmp", SDLRenderer);

	clock = SDL_GetTicks();
	while (isRunning)	// while window is running
	{
		deltaTime = SDL_GetTicks() - clock;
		clock = SDL_GetTicks();

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
				break;
			}
			if (event.key.keysym.sym == SDLK_a ||		// a for left movement
				event.key.keysym.sym == SDLK_d ||		// d for right movement
				event.key.keysym.sym == SDLK_SPACE)		// space for jump, vertical movement
			{
				keyHandler.LogEvent(event);
			}
		}
		keyHandler.GiveInstructions(&mainPlayer);
		mainPlayer.UpdateLocRect();

		//if (renderDelay >= (FRAME_TIME))
		//{
		//	// render HERE
		//	SDL_RenderClear(SDLRenderer);
		//	SDL_RenderCopy(SDLRenderer, mainPlayer.GetSpriteSheet(),
		//		&(mainPlayer.GetStateRect()), &(mainPlayer.GetLocRect()));
		//	SDL_RenderPresent(SDLRenderer);
		//	renderDelay -= (FRAME_TIME);
		//}

		// render HERE
		SDL_RenderClear(SDLRenderer);
		SDL_RenderCopy(SDLRenderer, mainPlayer.GetSpriteSheet(),
			&(mainPlayer.GetStateRect()), &(mainPlayer.GetLocRect()));
		SDL_RenderPresent(SDLRenderer);
		renderDelay -= (FRAME_TIME);


		renderDelay += deltaTime;
		if (deltaTime < FRAME_TIME)
			SDL_Delay(FRAME_TIME - deltaTime);
	}
}
