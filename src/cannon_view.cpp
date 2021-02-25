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


bool CannonView::inRange(std::shared_ptr<Actor> actor) {
    // get distance between cannon and parrot
    int dist = abs(actor->getBody()->GetPosition().x - this->cannon->getBody()->GetPosition().x);

    // max range = 30
    if (dist <= 30) {
        return true;
    }
    return false;
}


void CannonView::updateTarget(void) {
	// if no target: all this
    this->target = NULL;
	for (std::shared_ptr<Actor> a : this->cannon->getRoom()->getActorList()) {
		if (a->getAllegiance() == Allegiance::PARROT && a->isTarget() && this->inRange(a)) {
			this->target = a;
		}
	}
}

void CannonView::update(const float &dt) {
	this->updateTarget();

    if (this->target != NULL) {
        this->cannon->shoot();
        b2Vec2 dist = this->target->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
        float targetAngle = atan2(dist.y, dist.x);
        this->cannon->getOrientation() < targetAngle ? this->cannon->rotCounterclockwise() : this->cannon->rotClockwise();
    
    } else {
        this->cannon->rotateStop();
    }
}
