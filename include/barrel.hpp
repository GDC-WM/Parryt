#ifndef BARREL_HPP
#define BARREL_HPP

#include <box2d/box2d.h>

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Barrel : public Actor {
public:
	// set Width and Height of barrel
	static constexpr float WIDTH = 1.9;
	static constexpr float HEIGHT = 1.7;

	// main class
	Barrel(b2Vec2 position);

	const bool shouldCollide(const Actor &a) const override;

	virtual void draw(std::shared_ptr<sf::RenderWindow> window) override;

private:
	b2PolygonShape barrelShape;
	sf::Texture barrelTexture;
	sf::Sprite barrelSprite;
};


#endif