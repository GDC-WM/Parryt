#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "cannon.hpp"
#include "cannonball.hpp"


Cannon::Cannon(b2Vec2 position) : Actor(position) {
	this->allegiance = Allegiance::PIRATE;

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->bodyDef.enabled = false;
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// set carriage
	this->carriage.setOrigin(this->WIDTH, this->HEIGHT);
	this->carriage.setFillColor(sf::Color::Red);
	this->carriage.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));

	// set barrel
	this->barrel.setOrigin(0, this->barrelDimensions.y);
	this->barrel.setFillColor(sf::Color::White);
	this->barrel.setSize(sf::Vector2f(this->barrelDimensions.x * 2, this->barrelDimensions.y * 2));
}


void Cannon::shoot(void) {
	if (this->loadingCounter > 0) return;

	this->loadingCounter = this->LOAD_TIME;
	std::shared_ptr<Cannonball> cannonball = std::make_shared<Cannonball>(this->body->GetPosition(), 20);
	this->room->addActor(cannonball); // give actors access to the room they are in
	cannonball->getBody()->ApplyLinearImpulseToCenter(b2Vec2(cos(this->barrelAngle) * 50,
	                                                         sin(this->barrelAngle) * 50), true);
}


void Cannon::update(const float &dt) {
	this->barrelAngle += this->rotationVelocity;
	if (this->loadingCounter > 0) this->loadingCounter--;
}


void Cannon::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->carriage.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	this->carriage.setRotation(-this->body->GetAngle() * 180 / M_PI);
	window->draw(carriage);

	this->barrel.setPosition(this->getBody()->GetPosition().x,
	                        -this->getBody()->GetPosition().y);
	this->barrel.setRotation(-this->barrelAngle * 180 / M_PI);
	window->draw(barrel);
}
