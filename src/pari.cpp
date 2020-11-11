#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "pari.hpp"


Pari::Pari(b2Vec2 position) : Character(position) {
	this->allegiance = Allegiance::PARROT;

	this->acceleration = 60;
	this->jumpImpulse = 50;
	this->maxSpeed = 10;
	this->maxHealth = 100;

	// fix shape to body
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 2.4f;

	// set drawable
	texture.loadFromFile("../resources/running-sequence.png");
	this->sprite = sf::Sprite(texture, sf::IntRect(0,0,64,64));
	sprite.setScale(0.08,0.08);
	this->sprite.setOrigin(this->WIDTH, this->HEIGHT);

	// set old drawable
	this->drawable.setOrigin(this->WIDTH, this->HEIGHT);
	this->drawable.setFillColor(sf::Color::Green);
	this->drawable.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));
}


void Pari::draw(std::shared_ptr<sf::RenderWindow> window) {
	// old drawable
	this->drawable.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	//window->draw(drawable);

	this->sprite.setPosition(this->body->GetPosition().x - this->WIDTH - 2,
	                        -this->body->GetPosition().y - this->HEIGHT - 1);
	window->draw(this->sprite);
}
