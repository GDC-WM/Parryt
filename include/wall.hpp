#ifndef WALL_HPP
#define WALL_HPP


#include <box2d/box2d.h>

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Wall : public Actor {
	public:
		static constexpr float WIDTH = 0.1;

		Wall(float x, float y, float height);


	private:
		b2PolygonShape shape;
};


#endif
