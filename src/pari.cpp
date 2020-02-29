#include <SFML/Graphics.hpp>

#include "pari.h"
#include <iostream>

Pari::Pari(double x, double y) : Character(x, y, 64, 64, 10, 180, 200) {
	this->shape.setFillColor(sf::Color::Green);
}

const void Pari::draw(sf::RenderWindow &window) {
	this->shape.setSize(sf::Vector2f(this->width, this->height));
	this->shape.setPosition(this->x, this->y);
	window.draw(shape);
}
