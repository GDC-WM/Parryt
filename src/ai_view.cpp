#include <list>
#include <memory>

#include "ai_view.hpp"
#include "model.hpp"
#include "actor.hpp"


AIView::AIView(std::shared_ptr<Model> model, std::shared_ptr<Actor> actor) : View(model) {
	this->actor = actor;
	this->range = 30;
}


bool AIView::updateTarget(const Allegiance allegiance) {
	if (!this->model) return false;
	for (std::shared_ptr<Actor> a : this->model->getActorList()) {
		if (a->getAllegiance() == allegiance && a->isTargetable() && this->inRange(a)) {
			this->target = a;
			return true;
		}
	}
	this->target = NULL;
	return false;
}


bool AIView::inRange(std::shared_ptr<Actor> target) {
	b2Vec2 targetDist = target->getBody()->GetPosition() - this->actor->getBody()->GetPosition();
	return sqrt(pow(targetDist.x, 2) + pow(targetDist.y, 2)) <= this->range;
}
