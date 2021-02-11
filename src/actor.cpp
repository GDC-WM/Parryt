#include <memory>
#include <cmath>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "room.hpp"


Actor::Actor(b2Vec2 position) {
	this->bodyDef.position = position;
	this->bodyDef.userData.pointer = (uintptr_t)(this);
}


void Actor::setRoom(std::shared_ptr<Room> room) {
	this->room = room;
	this->body = this->room->getWorld()->CreateBody(&this->bodyDef);

	this->body->CreateFixture(&this->fixtureDef);
}
