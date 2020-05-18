#include <SFML/Graphics.hpp>
#include <iostream>

#include "platform.hpp"

Platform::Platform(double x, double y, double width) : Actor(x, y, width, 10) {
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(this->width, this->height));
	this->state = ActorState::INDEPENDENT;
}

const sf::Shape &Platform::getShape(void) const {
	return (this->shape);
}
