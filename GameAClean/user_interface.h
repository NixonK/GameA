// File:			user_interface.h
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	User interface file with window, renderer, and FPS specifications
//
// Notes:
//

#ifndef USER_INTERFACE_H_INCLUDED
#define USER_INTERFACE_H_INCLUDED

#include"includes.h"

class UserInterface
{
protected:
	SDL_Window *window;						// window to render textures on
	const int INIT_SCREEN_WIDTH = 800;		// 
	const int INIT_SCREEN_HEIGHT = 400;
	int screenWidth, screenHeight;
	float FPS = 60;
	SDL_Renderer *renderer;
	int imgFlags;
public:
	UserInterface();
	bool Init();
	SDL_Texture *LoadTexture(std::string filePath, SDL_Renderer *renderTarget);
	void CleanUp();

	SDL_Renderer *GetRenderer();
};

#endif