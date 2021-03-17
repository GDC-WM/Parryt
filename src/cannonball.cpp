#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
# include <iostream>
#include "actor.hpp"
#include "cannonball.hpp"


Cannonball::Cannonball(b2Vec2 position, float damage) : Actor(position) {
	this->allegiance = Allegiance::pirate;

	this->age = 0;
	// fix shape to body
	this->shape.m_radius = this->RADIUS;
	this->bodyDef.type = b2_dynamicBody;
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.5f;
	this->fixtureDef.friction = 3.0f;

	// set drawable
	texture.loadFromFile("../resources/cannonball.png");
	this->sprite = sf::Sprite(texture, sf::IntRect(0,0,64,64));
	sprite.setScale(0.08,0.08);
	this->sprite.setOrigin(this->RADIUS * 14, this->RADIUS * 14);

	// set old drawable
	this->drawable.setOrigin(this->RADIUS, this->RADIUS);
	this->drawable.setFillColor(sf::Color::Blue);
	this->drawable.setRadius(this->RADIUS);
}

const bool Cannonball::collides(const Actor &a) const {
	if (a.getAllegiance() == Allegiance::parrot) {
		std::cout << "cannonball collided with Pari" << std::endl; 
		if (-M_PI / 2 < angleBetweenPariAndCannonball && angleBetweenPariAndCannonball < M_PI / 2)
		{
			// only redirect projectile if mouse cursor is to the right of Pari (for debugging purposes)
			this->body->SetLinearVelocity(b2Vec2(100 * cos(angleBetweenPariAndCannonball), 100 * sin(angleBetweenPariAndCannonball)));
		}

	}
	return true; // not sure how this boolean matters, placeholder
	//return a.getBody()->GetLinearVelocity().y < 0; copied from platform.cpp
}


void Cannonball::update(const float &dt) {
	this->age++;
	if (this->age > 900) {
		this->room->removeActor(this->shared_from_this());
	}
}

void Cannonball::draw(std::shared_ptr<sf::RenderWindow> window) {
	float mouseCoordX = window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x - window->getView().getCenter().x;
	float mouseCoordY = window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y - window->getView().getCenter().y;
	this ->angleBetweenPariAndCannonball = atan2(mouseCoordY, mouseCoordX);
	this->drawable.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	this->drawable.setRotation(-this->body->GetAngle() * 180 / M_PI);
	//window->draw(drawable);

	this->sprite.setPosition(this->getBody()->GetPosition().x,
	                        -this->getBody()->GetPosition().y);
	this->sprite.setRotation(-this->body->GetAngle() * 180 / M_PI);
	window->draw(sprite);
}
