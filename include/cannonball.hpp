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

	const bool collides(const Actor &a) const override;

	void update(const float &dt) override;

	virtual void draw(std::shared_ptr<sf::RenderWindow> window);


private:
	b2CircleShape shape;
	float damage;
	int age;
	sf::CircleShape drawable;
	sf::Texture texture;
	sf::Sprite sprite;
	float angleBetweenPariAndCannonball; 
};


#endif
