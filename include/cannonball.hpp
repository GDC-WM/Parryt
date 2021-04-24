#ifndef CANNONBALL_HPP
#define CANNONBALL_HPP


#include <box2d/box2d.h>

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Cannonball : public Actor {
public:
	static constexpr float RADIUS = 0.7;

	Cannonball(b2Vec2 position, float damage);

	void onCollision(Actor &a) override;

	void update(void) override;

	void draw(std::shared_ptr<sf::RenderWindow> window) override;


private:
	b2CircleShape shape;
	float damage;
	int age; //TODO: make this based on chrono
	sf::CircleShape drawable;
	sf::Texture texture;
	sf::Sprite sprite;
};


#endif
