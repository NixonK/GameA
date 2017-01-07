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
#include"movement.h"

class Player : public UserInterface
{
protected:
	// Pointer to sprite sheet texture.
	SDL_Texture *spriteSheet;

	// Sprite sheet file name.
	const std::string SPRITE_SHEET_FILENAME = "sprite.png";

	// Original sprite sheet width and height.
	const int SPRITE_SHEET_WIDTH = 24;
	const int SPRITE_SHEET_HEIGHT = 28;

	// Sprite width and height based on sprite sheet sizes.
	int SPRITE_WIDTH, SPRITE_HEIGHT;

	// Sprite enlargement (because original sheet is very small).
	int SPRITE_GROW;

	// 1-6 sprite states of the sprite sheet.
	int spriteState;

	// Sprite sheet location on the screen and location of the current sprite.
	// on the sprite sheet.
	SDL_Rect spriteStateRect;
	SDL_Rect spriteLocRect;

	const int QUEUE_SIZE = 10;
	std::queue<SDL_Rect> locationQueue;
	std::queue<SDL_Rect> stateQueue;

	// More precise location x and y values for precision movement calculations.
	double locX;
	double locY;

	// Precision calculation for movement.
	double distanceToMove;

	// Floor of the screen, based on screen height.
	int screenFloor;

	// Number of possible jumps left for the player
	int numberJumps = 1;

	// Jump delay mechanism for number of frames, currently for testing.
	const int jumpDelay = (int)FPS;
	int jumpDelayCounter;
	bool jumpDelayed;

	// Vertical velocity of the player.
	double vertVel;

	// Distance to move for the lean and lunge animation.
	const double leanDistance = .5;
	const double lungeDistance = 5;

	// Horizontal jump movement, and jump strength that is affected by gravity.
	const double jumpDistance = 4.5;
	const double jumpStrength = 5;
	const double gravity = -.1;

public:
	/**
	 * Constructor for player class, initialise all the physics variables.
	 */
	Player();

	/**
	 * Destructor for player class, destroy texture and point them to nullptr.
	 */
	~Player();

	/**
	 * Load the sprite texture into the player class.
	 *
	 * @param spriteRenderer, the renderer to render the sprite on.
	 */
	void LoadSpriteTexture(SDL_Renderer *spriteRenderer);

	/**
	 * Attempt to start the jump.
	 */
	void AttemptJump();

	/**
	 * Move sprite in the given direction 'L' left or 'R' right.
	 *
	 * @param direction, movesprite in the given 'L' or 'R' direction.
	 */
	void MoveSprite(char direction);

	/**
	 * Halt the horizontal velocity of character and update to stopping animation.
     */
	void StopSprite();

	/**
	 * Update the sprite sheet rect to crop to the correct current state.
	 */
	void UpdateStateRect();

	/**
	 * Update the location of the player on the screen based on current velocity.
	 */
	void UpdateLocRect();

	/**
	 * Translate the precise x and y variables into usable int.
	 */
	void UpdateLocVariables();

	/**
	 * Return true if player is off the ground, false otherwise.
	 */
	bool IsOffGround();

	/**
	* Give instructions to this player depending on moveFlags and update location rect.
	*/
	void GiveInstruction(uMovementType moveFlags);



	/**
	 * Return the crop coordinates of the sprite sheet.
	 */
	SDL_Rect GetStateRect();

	/**
	* Return the crop coordinates of the sprite sheet.
	*/
	SDL_Rect GetQueueStateRect();

	/**
	 * Return the location coordinates of the sprite.
	 */
	SDL_Rect GetLocRect();

	/**
	* Return the location coordinates of the sprite at the front of the queue.
	*/
	SDL_Rect GetQueueLocRect();

	/**
	 * Return the sprite sheet texture.
	 */
	SDL_Texture *GetSpriteSheet();
};

#endif