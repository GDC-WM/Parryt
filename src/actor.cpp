#include <memory>
#include <cmath>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "room.hpp"


Actor::Actor(const b2Vec2 &position) {
	this->bodyDef.position = position;
}


void Actor::setRoom(std::shared_ptr<Room> room) {
	// initialize the actor
	this->room = room;
	this->body = this->room->getWorld()->CreateBody(&this->bodyDef);
	this->body->CreateFixture(&this->fixtureDef);

	// connect the actor to its body
	this->body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}

