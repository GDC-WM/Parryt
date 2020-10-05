#include "actor.hpp"

#include "math.h"
#define PI 3.14159265


Actor::Actor(float x, float y) {
	this->bodyDef.position.Set(x, y);
}


void Actor::setWorld(std::shared_ptr<b2World> world) {
	this->world = world;
	this->body = this->world->CreateBody(&this->bodyDef);
	this->body->CreateFixture(&this->fixtureDef);
}

void Actor::update(const float &dt) {
}
