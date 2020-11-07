#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "wall.hpp"


Wall::Wall(b2Vec2 position, float height) : Actor(position) {
	this->shape.SetAsBox(this->WIDTH, height);

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// set drawable
	this->drawable.setOrigin(this->WIDTH, height);
	this->drawable.setFillColor(sf::Color::White);
	this->drawable.setSize(sf::Vector2f(this->WIDTH * 2, height * 2));
}
