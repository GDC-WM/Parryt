#include <SFML/Graphics.hpp>
#include <iostream>

#include "platform.hpp"

Platform::Platform(double x, double y, double width) : Actor(x, y) {
	// fix shape to body
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;
	this->body->CreateFixture(&fixtureDef);

	// set drawable
	this->drawable.setFillColor(sf::Color::White);
	this->drawable.setSize(sf::Vector2f(width, 5));
}
