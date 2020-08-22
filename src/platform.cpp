#include <SFML/Graphics.hpp>
#include <iostream>

#include "platform.hpp"

Platform::Platform(double x, double y, double width) : Actor(x, y, width, Platform::HEIGHT) {
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(this->width, this->height));
	this->state = ActorState::INDEPENDENT;
	this->physical = true;
}
