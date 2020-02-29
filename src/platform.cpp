#include <SFML/Graphics.hpp>
#include <iostream>

#include "platform.h"

Platform::Platform(double x, double y, double width) : Actor(x, y, width, 10) {
	this->shape.setFillColor(sf::Color::White);
}

const void Platform::draw(sf::RenderWindow &window) {
	this->shape.setSize(sf::Vector2f(this->width, this->height));
	this->shape.setPosition(this->x, this->y);
	window.draw(shape);
}
