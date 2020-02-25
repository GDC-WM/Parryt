#include <SFML/Graphics.hpp>

#include "actor.h"
#include "character.h"
#include "pari.h"
#include <iostream>

Pari::Pari(double x, double y) : Character(x, y, 64, 64, 10, 180, 200) {
	this->shape.setSize(sf::Vector2f(this->width, this->height));
	this->shape.setFillColor(sf::Color::Green);
}

void Pari::draw(sf::RenderWindow &window) {
		this->shape.setPosition(this->x, this->y);
		window.draw(shape);
		std::cout << "drawn";

}
