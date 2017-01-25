// File:			sprite.cpp
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	Sprite class to serve as an abstract class for all sprite related
//				classes.
//
// Notes:
//

#include "sprite.h"
#include "user_interface.h"

void Sprite::LoadSpriteTexture(SDL_Renderer *spriteRenderer) {
	spriteSheet = UserInterface::LoadTexture(SDL_GetBasePath() + SPRITE_SHEET_FILENAME, spriteRenderer);
}


SDL_Rect Sprite::GetStateRect() {
	return spriteStateRect;
}

SDL_Rect Sprite::GetLocRect() {
	return spriteLocRect;
}

SDL_Texture *Sprite::GetSpriteSheet() {
	return spriteSheet;
}
