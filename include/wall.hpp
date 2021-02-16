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

	Wall(b2Vec2 position, float height);

	virtual void draw(std::shared_ptr<sf::RenderWindow> window);

private:
	b2PolygonShape shape;
	sf::RectangleShape drawable;
};


#endif
