// File:			player.cpp
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	Player class with SDL_Texture, physical, physics specifications
//				for the moving character. State and location parameters for the
//				sprite sheet texture are kept in SDL_Rect structs.
//
// Notes:
//

#include "player.h"

Player::Player() {
	spriteState = 0;

	spriteStateRect;
	spriteStateRect.w = SPRITE_WIDTH;
	spriteStateRect.h = SPRITE_HEIGHT;
	UpdateStateRect();

	spriteLocRect;
	locX = 0;
	locY = (double) (INIT_SCREEN_HEIGHT - (SPRITE_HEIGHT * SPRITE_GROW));
	UpdateLocVariables();
	spriteLocRect.w = SPRITE_WIDTH * SPRITE_GROW;
	spriteLocRect.h = SPRITE_HEIGHT * SPRITE_GROW;

	distanceToMove = 0.0;

	screenFloor = spriteLocRect.y;

	// const int numberJumps;
	//const int jumpDelay;
	jumpDelayCounter = jumpDelay;
	jumpDelayed = false;
	vertVel = 0.0;
	//const double leanDistance;
	//const double lungeDistance;
	//const double jumpDistance;
	//const double jumpStrength;
	//const double gravity;
}

Player::~Player() {
	SDL_DestroyTexture(spriteSheet);
	spriteSheet = nullptr;
	int i = 0;
	for (i; i < 1000; i++)
		std::cout << "player deleted" << std::endl;
}

void Player::LoadSpriteTexture(SDL_Renderer *spriteRenderer) {
	spriteSheet = LoadTexture(SDL_GetBasePath() + SPRITE_SHEET_FILENAME, spriteRenderer);
}

void Player::AttemptJump() {
	if (numberJumps > 0 && !jumpDelayed) {
		numberJumps--;
		jumpDelayed = true;
		vertVel = jumpStrength;
	}
}

void Player::MoveSprite(char direction) {
	if (IsOffGround()) {
		if (direction == 'R') {
			distanceToMove = jumpDistance;
			spriteState = 2;
		} else {
			distanceToMove = jumpDistance *-1;
			spriteState = 5;
		}
		UpdateStateRect();
		return;
	}

	if (direction == 'R') {
		switch (spriteState) {
			case 0: {
				spriteState = 1;	// into lean
				distanceToMove = leanDistance;
				break;
			}
			case 1: {
				spriteState = 2;	// into lunge
				distanceToMove = lungeDistance;
				break;
			}
			case 2: {
				spriteState = 1;	// into lunge prep
				distanceToMove = lungeDistance;
				break;
			}
			default: {
				spriteState = 1;	// other case; turn around into lean, 0 movement
				break;
			}
		}
	} else if (direction == 'L') {
		switch (spriteState) {
			case 3: {
				spriteState = 4;	// into lean
				distanceToMove = leanDistance *-1;
				break;
			}
			case 4: {
				spriteState = 5;	// into lunge
				distanceToMove = lungeDistance *-1;
				break;
			}
			case 5: {
				spriteState = 4;	// into lunge prep
				distanceToMove = lungeDistance *-1;
				break;
			}
			default: {
				spriteState = 4;	// other case; turn around into lean, 0 movement
				break;
			}
		}
	}
	UpdateStateRect();
}

void Player::StopSprite() {
	distanceToMove = 0;
	if (spriteState <= 2) {
		spriteState = 0;
	} else {
		spriteState = 3;
	}

	UpdateStateRect();
}

void Player::UpdateStateRect() {
	spriteStateRect.x = (spriteState % 3) * SPRITE_WIDTH;
	if (spriteState <= 2) {
		spriteStateRect.y = 0;
	} else {
		spriteStateRect.y = SPRITE_HEIGHT;
	}

	if (stateQueue.size() == QUEUE_SIZE) {
		stateQueue.pop();
	}
	stateQueue.push(spriteStateRect);
}

void Player::UpdateLocRect() {
	locX += distanceToMove;
	locY -= vertVel;
	if (IsOffGround()) {
		vertVel += gravity;
	}
	if (locY > screenFloor)	{
		locY = screenFloor;
		vertVel = 0.0;

		numberJumps++;
	}

	if (jumpDelayed) {
		jumpDelayCounter--;
		if (jumpDelayCounter == 0) {
			jumpDelayCounter = jumpDelay;
			jumpDelayed = false;
		}
	}
	UpdateLocVariables();
	std::cout << "x: " << locX << " y: " << locY <<
		" state: " << spriteState <<
		" vertVel: " << vertVel <<
		" IsOffGround: " << IsOffGround() <<
		" jumpDelayCounter: " << jumpDelayCounter << std::endl;
	//std::cout << static_cast<int>(Movement::JUMP) << std::endl;
}

void Player::UpdateLocVariables() {
	spriteLocRect.x = static_cast<int>(locX + 0.5);
	spriteLocRect.y = static_cast<int>(locY + 0.5);
	if (locationQueue.size() == QUEUE_SIZE) {
		locationQueue.pop();
	}
	locationQueue.push(spriteLocRect);
}

bool Player::IsOffGround() {
	return locY < screenFloor;
}

void Player::GiveInstruction(uMovementType moveFlags) {
	if (moveFlags & Movement::JUMP) {
		this->AttemptJump();
	}

	if (moveFlags & Movement::STOP) {
		this->StopSprite();
	} else if (moveFlags & Movement::LEFT) {
		this->MoveSprite('L');
	} else if (moveFlags & Movement::RIGHT) {
		this->MoveSprite('R');
	}

	this->UpdateLocRect();
}

SDL_Rect Player::GetStateRect() {
	return spriteStateRect;
}

SDL_Rect Player::GetQueueStateRect() {
	return stateQueue.front();
}

SDL_Rect Player::GetLocRect() {
	return spriteLocRect;
}

SDL_Rect Player::GetQueueLocRect() {
	return locationQueue.front();
}

SDL_Texture *Player::GetSpriteSheet() {
	return spriteSheet;
}