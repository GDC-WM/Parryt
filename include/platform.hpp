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

	Platform(b2Vec2 position, float width);

	const bool shouldCollide(const Actor &a) const override;

	virtual void draw(std::shared_ptr<sf::RenderWindow> window) override;

private:
	b2EdgeShape shape;
	sf::RectangleShape drawable;
};


#endif
