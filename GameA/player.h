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

#include "sprite.h"
#include <queue>

class Player : public Sprite {
private:
	// 1-6 sprite states of the sprite sheet.
	int spriteState;

	// Queue containing location and state rectangles.
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

	// Vertical velocity of the player.
	double vertVel;

	// Distance to move for the lean and lunge animation.
	const double leanDistance = .5;
	const double lungeDistance = 5;

	// Horizontal jump movement, and jump strength that is affected by gravity.
	const double jumpDistance = 4.5;
	const double jumpStrength = 5;
	const double gravity = -.1;

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
	* Give instructions to this player depending on moveFlags and update location rect.
	*/
	virtual void GiveInstruction(uMovementType moveFlags);


	/**
	* Return the crop coordinates of the sprite sheet.
	*/
	SDL_Rect GetQueueStateRect();

	/**
	* Return the location coordinates of the sprite at the front of the queue.
	*/
	SDL_Rect GetQueueLocRect();
};

#endif