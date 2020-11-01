#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "cannon.hpp"


Cannon::Cannon(float x, float y) : Actor(x, y) {
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// set drawable
	this->drawable.setOrigin(this->WIDTH, this->HEIGHT);
	this->drawable.setFillColor(sf::Color::Red);
	this->drawable.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));
}
