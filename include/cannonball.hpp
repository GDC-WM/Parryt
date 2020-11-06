#ifndef CANNONBALL_HPP
#define CANNONBALL_HPP


#include <box2d/box2d.h>

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Cannonball : public Actor {
	public:
		static constexpr float RADIUS = 0.5;

		Cannonball(float x, float y, float damage);


	private:
		b2CircleShape shape;
		float damage;
};


#endif
