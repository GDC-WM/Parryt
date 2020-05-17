#include <SFML/Graphics.hpp>
#include <iostream>

#include "platform.h"

Platform::Platform(double x, double y, double width) : Actor(x, y, width, 10) {
	this->shape.setFillColor(sf::Color::White);
	this->state = ActorState::INDEPENDENT;
}

sf::Shape &Platform::getShape(void) {
	this->shape.setSize(sf::Vector2f(this->width, this->height));
	return (this->shape);
}
