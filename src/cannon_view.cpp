#include <list>
#include <memory>
#include <cmath>

#include "view.hpp"
#include "cannon_view.hpp"
#include "cannon.hpp"

CannonView::CannonView(std::shared_ptr<LogicController> logic, std::shared_ptr<Cannon> cannon) : View(logic) {
	this->cannon = cannon;
	this->logic = logic;
}


bool CannonView::inRange(std::shared_ptr<Actor> target) {
	b2Vec2 targetDist = target->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
	return sqrt((pow(targetDist.x, 2) + pow(targetDist.y, 2))) <= this->cannon->getRange();
}


void CannonView::aimAt(std::shared_ptr<Actor> target) {
	//calculate angle of target's position using trig
	b2Vec2 targetVector = target->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
	float relativeAngle = this->cannon->getOrientation() - atan2(targetVector.y, targetVector.x);

	sin(relativeAngle) < 0 ? this->cannon->rotCounterclockwise() : this->cannon->rotClockwise();
}


bool CannonView::updateTarget() {
	std::list<std::shared_ptr<Actor>> actors = this->cannon->getRoom()->getActorList();
	for (std::shared_ptr<Actor> a : actors) {
		if (a->getAllegiance() == Allegiance::parrot && a->isTargetable() && this->inRange(a)) {
			this->target = a;
			return true;
		}
	}
	this->target = NULL;
	return false;
}


void CannonView::update(const float &dt) {
	if (this->updateTarget()) {
		this->aimAt(this->target);
		this->cannon->shoot();
	}
	else this->cannon->rotateStop();
}
