// File:			sprite.h
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	Sprite class to serve as an abstract class for all sprite related
//				classes.
//
// Notes:
//

#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "movement.h"

class Sprite {
protected:
	// Pointer to sprite sheet texture.
	SDL_Texture *spriteSheet;

	// Sprite sheet file name.
	std::string SPRITE_SHEET_FILENAME;

	// Original sprite sheet width and height.
	int SPRITE_SHEET_WIDTH;
	int SPRITE_SHEET_HEIGHT;

	// Sprite width and height based on sprite sheet sizes.
	int SPRITE_WIDTH;
	int SPRITE_HEIGHT;

	// Sprite enlargement (because original sheet is very small).
	int SPRITE_GROW;

	// Sprite sheet location on the screen and location of the current sprite on the sprite sheet.
	SDL_Rect spriteStateRect;
	SDL_Rect spriteLocRect;

public:
	/**
	* Constructor for sprite class, initialise all the physics variables.
	*/
	Sprite() {};

	/**
	* Destructor for sprite class, destroy texture and point them to nullptr.
	*/
	virtual ~Sprite() {};

	/**
	* Load the sprite texture into the player class.
	*
	* @param spriteRenderer, the renderer to render the sprite on.
	*/
	void LoadSpriteTexture(SDL_Renderer *spriteRenderer);

	/**
	* Give instructions to this sprite; virtual function will depend on
	* subclass specific implementation.
	*/
	virtual void GiveInstruction(uMovementType moveFlags) = 0;


	/**
	* Return the crop coordinates of the sprite sheet.
	*/
	SDL_Rect GetStateRect();

	/**
	* Return the location coordinates of the sprite.
	*/
	SDL_Rect GetLocRect();

	/**
	* Return the sprite sheet texture.
	*/
	SDL_Texture *GetSpriteSheet();
};

#endif