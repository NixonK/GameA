// File:			player.h
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	Player class with SDL_Texture, physical, physics specifications
//				for the moving character. State and location parameters for the
//				sprite sheet texture are kept in SDL_Rect structs.
//
// Notes:
//

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include"user_interface.h"

class Player : public UserInterface
{
protected:
	SDL_Texture *spriteSheet;
	const int SPRITE_SHEET_WIDTH = 24;
	const int SPRITE_SHEET_HEIGHT = 28;
	int SPRITE_WIDTH, SPRITE_HEIGHT;
	int SPRITE_GROW;
	int spriteState;
	SDL_Rect spriteStateRect;
	SDL_Rect spriteLocRect;
	double locX;
	double locY;

	double distanceToMove;

	int screenFloor;
	
	int numberJumps;
	const int jumpDelay = (int)FPS;
	int jumpDelayCounter;
	bool jumpDelayed;
	double vertVel;
	const double leanDistance = .5;
	const double lungeDistance = 5;
	const double jumpDistance = 4.5;	
	const double jumpStrength = 5;
	const double gravity = -.1;
public:
	Player();
	void LoadSpriteTexture(SDL_Renderer *spriteRenderer);

	void AttemptJump();
	void MoveSprite(char direction);
	void StopSprite();

	void UpdateStateRect();
	void UpdateLocRect();
	void UpdateLocVariables();

	bool IsOffGround();

	SDL_Rect GetStateRect();
	SDL_Rect GetLocRect();
	SDL_Texture *GetSpriteSheet();

	void CleanUp();
};

#endif 