#ifndef CANNONBALL_HPP
#define CANNONBALL_HPP


#include <cmath>
#include <box2d/box2d.h>

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Cannonball: public Actor {
	public:
		static constexpr float RADIUS = 0.5;

		Cannonball(float damage);


	private:
		float damage;
};


#endif
