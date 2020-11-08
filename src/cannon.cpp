#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "cannon.hpp"
#include "cannonball.hpp"


Cannon::Cannon(b2Vec2 position) : Actor(position) {
	this->allegiance = Allegiance::PIRATE;

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// set carriage
	this->barrel.setOrigin(this->WIDTH, this->HEIGHT);
	this->barrel.setFillColor(sf::Color::Red);
	this->barrel.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));

	// set barrel
	this->barrel.setOrigin(this->WIDTH, this->HEIGHT);
	this->barrel.setFillColor(sf::Color::Red);
	this->barrel.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));
}


void Cannon::shoot(void) {
	Cannonball(this->body->GetPosition(), 20);
}


void Cannon::update(const float &dt) {
	this->barrelAngle += this->rotationVelocity;
}


void Cannon::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->carriage.setRotation(-this->body->GetAngle() * 180 / M_PI);

	this->barrel.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	this->barrel.setRotation(-this->barrelAngle * 180 / M_PI);
	window->draw(barrel);
}
