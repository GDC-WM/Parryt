#include <list>
#include <memory>
#include <cmath>

#include "view.hpp"
#include "cannon_view.hpp"
#include "cannon.hpp"

CannonView::CannonView(std::shared_ptr<Model> model, std::shared_ptr<Cannon> cannon) : AIView(model, cannon) {
	this->cannon = cannon;
}


bool CannonView::inRange(std::shared_ptr<Actor> target) {
	return AIView::inRange(target); // make this method do something later
}


void CannonView::aimAt(std::shared_ptr<Actor> target) {
	// calculate angle of target's position
	b2Vec2 targetVector = target->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
	float relativeAngle = this->cannon->getOrientation() - atan2(targetVector.y, targetVector.x);

	sin(relativeAngle) < 0 ? this->cannon->rotCounterclockwise() : this->cannon->rotClockwise();
}


void CannonView::update(const float &dt) {
	if (this->updateTarget(Allegiance::parrot)) {
		this->aimAt(this->target);
		this->cannon->shoot();
	}
	else this->cannon->rotateStop();
}
