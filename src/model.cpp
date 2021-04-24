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
	actor->setWorld(this->world);
	this->actorList.push_back(actor);
}


void Model::reset(void) {
	actorList.clear();
}


void Model::update(const float &dt) {
	// step the box2d clock forward
	this->world->Step(dt / 1000, 8, 3); // convert milliseconds to seconds

	// update actors in the actor list
	std::list<std::shared_ptr<Actor>>::iterator actor_iter = this->actorList.begin();
	while (actor_iter != this->actorList.end()) {
		std::shared_ptr<Actor> actor = *actor_iter;
		actor->update(dt);

		// check if dead
		if (actor->isDead()) {
			this->world->DestroyBody(actor->getBody());
			this->actorList.erase(actor_iter++);
		}
		else{
			actor_iter++;
		}
	}
}
