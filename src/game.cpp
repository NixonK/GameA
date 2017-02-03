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

Game::Game(int fps) {
	isRunning = true;
	//SDL_Event event;
	//KeyHandler keyHandler;
	// float FPS = 60;
	FRAME_TIME = (1.0f / fps) * 1000.0f;  // milliseconds per frame
	clock = 0.0f;
	deltaTime = 0.0f;
	renderDelay = 0.0f;
}

Game::~Game() {
	// Player object loaded with automatic storage duration; will be deleted when out of scope.
	// Player is loaded with automatic storage, no need to manually delete.
}

Player *Game::GetPlayer() {
	return &mainPlayer;
}

void Game::Execute(SDL_Renderer *SDLRenderer) {
	// Select the color for drawing. It is set to red here.
	SDL_SetRenderDrawColor(SDLRenderer, 255, 75, 75, 255);
	// Clear the entire screen to our selected color.
	SDL_RenderClear(SDLRenderer);
	// Up until now everything was drawn behind the scenes.
	// This will show the new, red contents of the window.
	SDL_RenderPresent(SDLRenderer);

	try {
		mainPlayer.LoadSpriteTexture(SDLRenderer);

		Player shadowPlayer;
		shadowPlayer.LoadSpriteTexture(SDLRenderer);

		clock = static_cast<float>(SDL_GetTicks());
		while (isRunning) {	// while window is running
			deltaTime = static_cast<float>(SDL_GetTicks() - clock);
			clock = static_cast<float>(SDL_GetTicks());

			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT) {
					isRunning = false;
					break;
				}

				if ((event.type == SDL_KEYDOWN) || (event.type = SDL_KEYUP)) {
					if (event.key.keysym.sym == SDLK_a ||		// a for left movement
						event.key.keysym.sym == SDLK_d ||		// d for right movement
						event.key.keysym.sym == SDLK_SPACE)		// space for jump, vertical movement
					{
						keyHandler.LogEvent(event);
					}
				}
			}
			mainPlayer.GiveInstruction(keyHandler.GetInstructions());

			shadowPlayer.GiveInstruction(keyHandler.GetInstructions());

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
			SDL_RenderCopy(SDLRenderer, shadowPlayer.GetSpriteSheet(),
				&(shadowPlayer.GetQueueStateRect()), &(shadowPlayer.GetQueueLocRect()));

			SDL_RenderPresent(SDLRenderer);
			renderDelay -= FRAME_TIME;


			renderDelay += deltaTime;
			if (deltaTime < FRAME_TIME) {
				SDL_Delay(static_cast<Uint32>(FRAME_TIME - deltaTime));
			}
		}
	}
	catch (std::exception& e) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", e.what(), NULL);
	}
}
