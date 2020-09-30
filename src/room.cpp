#include "box2d/box2d.h"
#include <memory>

#include "actor.hpp"
#include "room.hpp"


Room::Room(void) {
	this->world = std::make_shared<b2World>(b2Vec2(0,-10));
}

void Room::addActor(std::shared_ptr<Actor> actor) {
	actor->setWorld(this->world);
	this->actorList.push_back(actor);
}

void Room::reset(void) {
    actorList.clear();
}

void Room::update(const float &dt) {
	this->world->Step(dt, 8, 3);
}
