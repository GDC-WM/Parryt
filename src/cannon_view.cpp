#include <list>
#include <memory>
#include <cmath>

#include "view.hpp"
#include "cannon_view.hpp"
#include "cannon.hpp"

CannonView::CannonView(std::shared_ptr<LogicController> logic, std::shared_ptr<Cannon> cannon) : AIView(logic,cannon) {
	this->cannon = cannon;
	this->range = this->cannon->getRange();
}


void CannonView::aimAt(std::shared_ptr<Actor> target) {
	//calculate angle of target's position using trig
	b2Vec2 targetDist = target->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
	float targetAngle = atan2(targetDist.y, targetDist.x);
	this->cannon->getOrientation() < targetAngle ? this->cannon->rotCounterclockwise() : this->cannon->rotClockwise();
}


void CannonView::update(const float &dt) {
	if (this->updateTarget(Allegiance::PARROT)) {
		this->aimAt(this->target);
		this->cannon->shoot();
	}
	else this->cannon->rotateStop();
}
