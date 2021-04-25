#include <list>
#include <memory>
#include <box2d/box2d.h>
#include <queue>

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
	this->actorPriorityQueue.push(actor);
}


void Model::reset(void) {
	actorList.clear();
}


void Model::update(void) {
	// step the box2d clock forward
	this->world->Step(16.0f / 1000, 8, 3); // convert milliseconds to seconds

	// update actors in the actor list
	std::list<std::shared_ptr<Actor>>::iterator actorIter = this->actorList.begin();
	while (actorIter != this->actorList.end()) {
		std::shared_ptr<Actor> actor = *actorIter;
		actor->update();

		// remove if dead
		if (actor->isDead()) {
			this->world->DestroyBody(actor->getBody());
			actorIter = this->actorList.erase(actorIter);
			continue;
		}
		actorIter++;
	}
}
