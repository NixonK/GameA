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
	const std::string SPRITE_SHEET_FILENAME;

	// Original sprite sheet width and height.
	const int SPRITE_SHEET_WIDTH;
	const int SPRITE_SHEET_HEIGHT;

	// Sprite width and height based on sprite sheet sizes.
	const int SPRITE_WIDTH;
	const int SPRITE_HEIGHT;

	// Sprite enlargement (because original sheet is very small).
	const int SPRITE_GROW;

	// Sprite sheet location on the screen and location of the current sprite on the sprite sheet.
	SDL_Rect spriteStateRect;
	SDL_Rect spriteLocRect;

public:
	/**
	* Constructor for sprite class, initialise all the physics variables.
	* 
	* @param spriteSheetFilename,	the sprite's sprite sheet filename.
	* @param spriteSheetWidth,		the sprite sheet width.
	* @param spriteSheetHeight,		the sprite sheet height.
	* @param spriteWidth,			the width of a single sprite on the sheet.
	* @param spriteHeight,			the height of a single sprite on the sheet.
	* @param spriteGrow,			the sprite enlargement factor.
	*/
	Sprite(std::string spriteSheetFilename, int spriteSheetWidth, int spriteSheetHeight, int spriteWidth, int spriteHeight, int spriteGrow) :
		SPRITE_SHEET_FILENAME(spriteSheetFilename),
		SPRITE_SHEET_WIDTH(spriteSheetWidth),
		SPRITE_SHEET_HEIGHT(spriteSheetHeight),
		SPRITE_WIDTH(spriteWidth),
		SPRITE_HEIGHT(spriteHeight),
		SPRITE_GROW(spriteGrow)
		{};

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