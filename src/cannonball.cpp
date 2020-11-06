#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "cannonball.hpp"


Cannonball::Cannonball(float x, float y, float damage) : Actor(x, y) {
	this->allegiance = Allegiance::PARROT;

	// fix shape to body
	this->shape.m_radius = this->RADIUS;
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 2.4f;

	// set drawable
	this->drawable.setOrigin(this->RADIUS, this->RADIUS);
	this->drawable.setFillColor(sf::Color::Green);
	this->drawable.setSize(sf::Vector2f(this->RADIUS * 2, this->RADIUS * 2));
}
