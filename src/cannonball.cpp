#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "cannonball.hpp"


Cannonball::Cannonball(b2Vec2 position, float damage) : Actor(position) {
	this->allegiance = Allegiance::PIRATE;

	// fix shape to body
	this->shape.m_radius = this->RADIUS;
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 2.4f;

	// set drawable
	this->drawable.setOrigin(this->RADIUS, this->RADIUS);
	this->drawable.setFillColor(sf::Color::Black);
	this->drawable.setSize(sf::Vector2f(this->RADIUS * 2, this->RADIUS * 2));
}


void Cannonball::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->drawable.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	this->drawable.setRotation(-this->body->GetAngle() * 180 / M_PI);
	window->draw(drawable);
}
