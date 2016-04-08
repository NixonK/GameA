// File:			user_interface.cpp
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	User interface file with window, renderer, and FPS specifications
//
// Notes:
//

#include"user_interface.h"
#include"game.h"

UserInterface::UserInterface()
{
	window = nullptr;
	//const int INIT_SCREEN_WIDTH;
	//const int INIT_SCREEN_HEIGHT;
	screenWidth = NULL;
	screenHeight = NULL;
	//const float FPS;
	renderer = nullptr;
	imgFlags = NULL;
}

UserInterface::~UserInterface()
{
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_Quit();
}

bool UserInterface::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	imgFlags = IMG_INIT_PNG;
	if (IMG_Init(imgFlags) != imgFlags)
		std::cout << "Erro: " << IMG_GetError() << std::endl;

	if ((window = SDL_CreateWindow(
		"GameA TEST",				// window title
		SDL_WINDOWPOS_CENTERED,		// initial x position
		SDL_WINDOWPOS_CENTERED,		// initial y position
		INIT_SCREEN_WIDTH,			// width, in pixels
		INIT_SCREEN_HEIGHT,			// height, in pixels
		SDL_WINDOW_RESIZABLE)) == NULL)
		return false;

	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED))
		== NULL)
		return false;

	return true;
}

SDL_Texture *UserInterface::LoadTexture(std::string filePath, SDL_Renderer * renderTarget)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str());
	if (!surface)
		std::cout << "Error IMG_Load: " << filePath.c_str() << std::endl;
	else
	{
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (!texture)
			std::cout << "Error texture not created." << filePath.c_str() << std::endl;
	}
	SDL_FreeSurface(surface);

	return texture;
}

SDL_Renderer *UserInterface::GetRenderer()
{
	return renderer;
}

