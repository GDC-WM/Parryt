#include <memory>
#include <cmath>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"


Actor::Actor(const b2Vec2 &position) {
	this->bodyDef.position = position;
}


void Actor::setRoom(std::shared_ptr<b2World> world) {
	// initialize the actor and set its room
	this->body = world->CreateBody(&this->bodyDef);
	this->body->CreateFixture(&this->fixtureDef);

	// connect the actor to its body
	this->body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}

