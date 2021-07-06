#ifndef GLOB_HPP
#define GLOB_HPP


#include <list>
#include <memory>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>


namespace glob {
	inline extern const float scale = 0.08;

	/*
	 * Define what side of the fight the actor is on
	 */
	enum class Allegiance { parrot, pirate, neutral };

	/*
	 * How does an actor collide?
	 */
	enum class CollisionID { solid };

	/*
	 * Define a direction
	 */
	enum class Dir { front, back, left, right, up, down, none };

	inline extern const b2Vec2 convertVec(sf::Vector2f sfmlVec) { return b2Vec2(sfmlVec.x, -sfmlVec.y); }

	inline extern const sf::Vector2f convertVec(b2Vec2 b2dVec) { return sf::Vector2f(b2dVec.x, -b2dVec.y); }
}

#endif
