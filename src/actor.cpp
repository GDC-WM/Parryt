#include <memory>
#include <cmath>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"


Actor::Actor(float x, float y) {
	this->bodyDef.position.Set(x, y);
}


void Actor::setWorld(std::shared_ptr<b2World> world) {
	this->world = world;
	this->body = this->world->CreateBody(&this->bodyDef);
	this->body->CreateFixture(&this->fixtureDef);
}


void Actor::updateDrawable(void) {
	this->drawable.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	this->drawable.setRotation(-this->getBody()->GetAngle() * 180 / M_PI);
}


const sf::Vector2f Actor::getDrawableCenter(void) const {
	return sf::Vector2f(this->drawable.getPosition().x + this->drawable.getSize().x / 2,
	                    this->drawable.getPosition().y + this->drawable.getSize().y / 2);
}


void Actor::update(const float &dt) {

}
