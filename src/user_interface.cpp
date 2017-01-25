// File:			user_interface.cpp
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	User interface file with window, renderer, and FPS specifications
//
// Notes:
//

#include "user_interface.h"
#include "game.h"

UserInterface::UserInterface() {
	window = nullptr;
	renderer = nullptr;
}

UserInterface::~UserInterface() {
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_Quit();
}

bool UserInterface::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
		std::cout << "Error with initializing PNG support: " << IMG_GetError() << std::endl;

	if ((window = SDL_CreateWindow(
		"GameA TEST",				// window title
		SDL_WINDOWPOS_CENTERED,		// initial x position
		SDL_WINDOWPOS_CENTERED,		// initial y position
		ScreenProperties::INIT_SCREEN_WIDTH,			// width, in pixels
		ScreenProperties::INIT_SCREEN_HEIGHT,		// height, in pixels
		SDL_WINDOW_RESIZABLE)) == NULL)
		return false;

	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
		return false;

	return true;
}

SDL_Texture *UserInterface::LoadTexture(std::string filePath, SDL_Renderer * renderTarget) {
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str());
	if (!surface) {
		throw std::runtime_error("Could not load texture with file at \"" + filePath + "\"");
	} else {
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (!texture)
			throw std::runtime_error("Could not load texture with file: " + filePath);
	}
	SDL_FreeSurface(surface);

	return texture;
}

SDL_Renderer *UserInterface::GetRenderer() {
	return renderer;
}

