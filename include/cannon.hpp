#ifndef PLATFORM_H
#define PLATFORM_H


#include <box2d/box2d.h>

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Cannon: public Actor {

	public:
		static constexpr float WIDTH = 0.5;
		static constexpr float HEIGHT = 0.5;
		static constexpr float ROTATION_SPEED = 1;

		Cannon(float x, float y);
};


#endif
