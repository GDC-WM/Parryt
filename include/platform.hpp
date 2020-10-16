#ifndef PLATFORM_H
#define PLATFORM_H


#include <box2d/box2d.h>

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Platform : public Actor {

	public:
		static constexpr double HEIGHT = 0.1;

		Platform(double x, double y, double width);
};


#endif
