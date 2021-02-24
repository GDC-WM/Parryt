#include <list>
#include <memory>
#include<cmath>

#include "view.hpp"
#include "cannon_view.hpp"
#include "cannon.hpp"

CannonView::CannonView(std::shared_ptr<LogicController> logic, std::shared_ptr<Cannon> cannon) : View(logic) {
	this->cannon = cannon;
    this->logic = logic;
	//this->cannon->rotateClockwise();
}


bool CannonView::inRange(std::shared_ptr<Actor> actor) {
	return true; // placeholder
}


void CannonView::updateTarget(void) {
	// if no target: all this
	for (std::shared_ptr<Actor> a : this->cannon->getRoom()->getActorList()) {
		if (a->getAllegiance() == Allegiance::PARROT && a->isTarget() && this->inRange(a)) {
			this->target = a;
		}
	}
}

float round2(float var) {
    float value = (int) (var * 100 + .5);
    return (float) value/100;
}

void CannonView::update(const float &dt) {
	this->cannon->shoot();

    // Anna's method
    this->updateTarget();

    b2Vec2 dist = this->target->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
    float targetAngle = (float) atan2(dist.y, dist.x);

    if (this->cannon->barrelAngle < targetAngle) {

    }

    // mod to check remainder
    this->cannon->rotateCounterclockwise();
    if (abs(this->cannon->barrelAngle) >= 6.28) {
        this->cannon->barrelAngle = 0;
    }

    if (this->cannon->barrelAngle < targetAngle) {
        this->cannon->rotateCounterclockwise();
    } else {
        this->cannon->rotateClockwise();
    }
}
