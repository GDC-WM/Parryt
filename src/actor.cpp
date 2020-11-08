#include <memory>
#include <cmath>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"


Actor::Actor(b2Vec2 position) {
	this->bodyDef.position = position;
}


void Actor::setWorld(std::shared_ptr<b2World> world) {
	this->world = world;
	this->body = this->world->CreateBody(&this->bodyDef);
	this->body->CreateFixture(&this->fixtureDef);
}


void Actor::update(const float &dt) {

}


const sf::Vector2f Actor::getDrawableCenter(void) const {
	return sf::Vector2f(this->drawable.getPosition().x + this->drawable.getSize().x / 2,
	                    this->drawable.getPosition().y + this->drawable.getSize().y / 2);
}
