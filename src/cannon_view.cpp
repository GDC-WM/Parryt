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

bool CannonView::inRange(std::shared_ptr<Actor> target){
	b2Vec2 distTarget = target->getBody()->GetPosition();
	if(sqrt((pow(distTarget.x, 2) + pow(distTarget.y, 2)))<=this->cannon->getRange()){
		return true;
	}
	return false;
}

void CannonView::aimAt(std::shared_ptr<Actor> t){
	//calculate angle of target's position using trig
	b2Vec2 dist = t->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
	float targetAngle = atan2(dist.y, dist.x);
	this->cannon->getOrientation() < targetAngle ? this->cannon->rotCounterclockwise() : this->cannon->rotClockwise();
	
}

void CannonView::updateTarget(){
	std::list<std::shared_ptr<Actor>> actors = this->cannon->getRoom()->getActorList();
	for(std::shared_ptr<Actor> a : actors){
		if(a->getAllegiance() == Allegiance::PARROT && a->isTarget() && this->inRange(a)){
			this->target = a;
		}
	}
}

void CannonView::update(const float &dt) {
	this->updateTarget();
	if(this->target != NULL){
		this->aimAt(this->target);
		this->cannon->shoot();
	}	
}
