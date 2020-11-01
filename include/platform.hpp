#ifndef PLATFORM_HPP
#define PLATFORM_HPP


#include <box2d/box2d.h>

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Platform : public Actor {
	public:
		static constexpr float HEIGHT = 0.1;

		Platform(float x, float y, float width);
};


#endif
