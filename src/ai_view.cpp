#include <list>
#include <memory>

#include "logic_controller.hpp"
#include "view.hpp"
#include "character.hpp"
#include "ai_view.hpp"

AIView::AIView(std::shared_ptr<LogicController> logic, std::shared_ptr<Actor> actor) : View(logic) {
	this->actor = actor;
	this->logic = logic;
	this->range = 30;
}

bool AIView::updateTarget(const Allegiance allegiance) {
    std::list<std::shared_ptr<Actor>> actors = this->actor->getRoom()->getActorList();
	for (std::shared_ptr<Actor> a : actors) {
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
	return sqrt((pow(targetDist.x, 2) + pow(targetDist.y, 2))) <= this->range;
}

void AIView::update(const float &dt) {
	//?? should this be in here? or in individual views
}
