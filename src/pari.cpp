#include <SFML/Graphics.hpp>

#include "pari.h"
#include <iostream>

Pari::Pari(double x, double y) : Character(x, y, 64, 64, 10, 180, 200) {
	this->shape.setFillColor(sf::Color::Green);
}

sf::Shape &Pari::getShape(void) {
	this->shape.setSize(sf::Vector2f(this->width, this->height));
	return (this->shape);
}
