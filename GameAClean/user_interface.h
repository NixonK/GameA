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
	// Window to render textures on.
	SDL_Window *window;

	// Initial window width and height.
	const int INIT_SCREEN_WIDTH = 800;
	const int INIT_SCREEN_HEIGHT = 400;

	// Window width and height.
	int screenWidth, screenHeight;

	// FPS used for the game.
	const float FPS = 60;

	// Renderer for the game.
	SDL_Renderer *renderer;

	// Flag used for checking image initialisation errors.
	int imgFlags;

public:
	/**
	 * Constructor that sets rendering components to NULL.
	 */
	UserInterface();

	/**
	 * Destructor that destroys windows and renderer pointer to object,
	 * then points them to nullptr and quit SDL.
	 */
	~UserInterface();

	/**
 	 * Initialises and creates the game window and renderer.
	 */
	bool Init();

	/**
	 * Loads image into the game renderer as a texture.
	 *
	 * @param filePath file path of image to load as texture.
	 * @param renderTarget target of renderer used for the game.
	 */
	SDL_Texture *LoadTexture(std::string filePath, SDL_Renderer *renderTarget);



	/**
	* Returns pointer to game renderer.
	*/
	SDL_Renderer *GetRenderer();
};

#endif