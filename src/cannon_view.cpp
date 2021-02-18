#include <list>
#include <memory>

#include "view.hpp"
#include "cannon_view.hpp"
#include "cannon.hpp"


CannonView::CannonView(std::shared_ptr<LogicController> logic, std::shared_ptr<Cannon> cannon) : View(logic) {
	this->cannon = cannon;
	this->cannon->rotateClockwise();
}


bool CannonView::inRange(std::shared_ptr<Actor> actor) {
	// true if in range
	// false if not
}


void CannonView::updateTarget() {
	// if no target: all this
	for (std::shared_ptr<Actor> a : this->cannon->getRoom()->getActorList()) {
		if (a->getAllegiance() == Allegiance::PARROT && a->isTarget() && this->inRange(a)) {
			this->target = a;
		}
	}
}


void CannonView::update(const float &dt) {
	this->cannon->shoot();
}
