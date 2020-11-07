#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "cannon.hpp"
#include "cannonball.hpp"


Cannon::Cannon(float x, float y) : Actor(x, y) {
	this->allegiance = Allegiance::PIRATE;

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// set drawable
	this->drawable.setOrigin(this->WIDTH, this->HEIGHT);
	this->drawable.setFillColor(sf::Color::Red);
	this->drawable.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));
}


void Cannon::shoot(void) {
	Cannonball(this->body->GetPosition().x, this->body->GetPosition().y, 20);
}


void Cannon::update(const float &dt) {
	this->orientation += this->rotationVelocity;
}
