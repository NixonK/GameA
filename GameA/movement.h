// File:			key_handler.h
// Author:			Nixon Kwok
// Contributors:	a
//
// Description:	Movement enum class that contains movement bit flags and
//              convenient overloading operators.
//
// Notes:
//

#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED

#include "includes.h"

/**
 * State of movement.
 */
enum class Movement : unsigned char {
	BLANK = 0x00,
	STOP = 0x01,
	JUMP = 0x02,
	LEFT = 0x04,
	RIGHT = 0x08,
};

/**
 * Underlying Movement type
 */
typedef std::underlying_type<Movement>::type uMovementType;

inline uMovementType& operator|=(uMovementType& a, Movement b) {
	a |= static_cast<uMovementType>(b);
	return a;
}

inline uMovementType operator&(uMovementType a, Movement b) {
	return a & static_cast<uMovementType>(b);
}

#endif