#include <list>
#include <memory>
#include <box2d/box2d.h>

#include "actor.hpp"
#include "room.hpp"


Room::Room(void) {
	this->world = std::make_shared<b2World>(b2Vec2(0,-10));
}


void Room::addActor(std::shared_ptr<Actor> actor) {
	actor->setRoom(this->shared_from_this());
	this->actorList.push_back(actor);
}


void Room::removeActor(std::shared_ptr<Actor> actor) {
	this->killList.push_back(actor);
}


void Room::reset(void) {
    actorList.clear();
}


void Room::update(const float &dt) {
	// step the box2d clock forward
	this->world->Step(dt / 1000, 8, 3); // convert milliseconds to seconds

	// update all actors in the actor list
	if (this->actorList.size() > 0) {
		for (std::shared_ptr<Actor> actor : this->actorList) {
			actor->update(dt);
		}
	}
	if (this->killList.size() > 0) {
		for (std::shared_ptr<Actor> actor : this->killList) {
			this->actorList.remove(actor);
		}
	}
}
