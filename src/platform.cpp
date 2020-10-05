#include <SFML/Graphics.hpp>
#include <iostream>

#include "platform.hpp"

Platform::Platform(double x, double y, double width) : Actor(x, y) {
	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// set drawable
	this->drawable.setFillColor(sf::Color::White);
	this->drawable.setSize(sf::Vector2f(width, 5));
}
