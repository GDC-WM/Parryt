#ifndef PLATFORM_H
#define PLATFORM_H

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Platform : public Actor {

	private:
		b2PolygonShape shape;

	public:
		static constexpr double HEIGHT = 10;

		Platform(double x, double y, double width);
};

#endif
