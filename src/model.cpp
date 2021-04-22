#include <list>
#include <memory>
#include <box2d/box2d.h>

#include "model.hpp"
#include "actor.hpp"
#include "contact_filter.hpp"
#include "contact_listener.hpp"


Model::Model(void) {
	this->world = std::make_shared<b2World>(b2Vec2(0,-60)); /* Set Gravity */
	this->world->SetContactFilter(&this->contact_filter);
	this->world->SetContactListener(&this->contact_listener);
}


void Model::addActor(std::shared_ptr<Actor> actor) {
	actor->setRoom(this->world);
	this->actorList.push_back(actor);
}


void Model::removeActor(std::shared_ptr<Actor> actor) {
	this->actorKillList.push_back(actor);
}


void Model::reset(void) {
	actorList.clear();
}


void Model::update(const float &dt) {
	// step the box2d clock forward
	this->world->Step(dt / 1000, 8, 3); // convert milliseconds to seconds

	// update all actors in the actor list
	if (this->actorList.size() > 0) {
		for (std::shared_ptr<Actor> actor : this->actorList) actor->update(dt);
	}

	// kill marked actors
	if (this->actorKillList.size()) {
		for (std::shared_ptr<Actor> actor : this->actorKillList) {
			this->actorList.remove(actor);
			this->world->DestroyBody(actor->getBody());
		}
		this->actorKillList.clear();
	}
}
