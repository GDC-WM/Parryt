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

bool CannonView::inRange(std::shared_ptr<Actor> target){
	//true if in range
	//false if not
	//have to aim cannon at target before we can determine if it is in range auuugh
	this->aimAt(target);
	//then calculate if in range using arc 
	return true;
}

void CannonView::aimAt(std::shared_ptr<Actor> t){
	//calculate angle of target's position using trig
	b2Vec2 dist = this->target->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
    int targetAngle = atan2(dist.y, dist.x);
	while(this->cannon->barrelAngle < targetAngle){
		this->cannon->rotateCounterclockwise();
		if(this->cannon->barrelAngle == targetAngle){
			this->cannon->rotateStop();
		}
	}

	while(this->cannon->barrelAngle > targetAngle){
		this->cannon->rotateClockwise();
		if(this->cannon->barrelAngle == targetAngle){
			this->cannon->rotateStop();
		}
	}
}

void CannonView::updateTarget(){
	//if no target: all this
	std::list<std::shared_ptr<Actor>> actors = this->cannon->getRoom()->getActorList();
	for(std::shared_ptr<Actor> a : actors){
		if(a->getAllegiance() == Allegiance::PARROT && a->isTarget() && this->inRange(a)){
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

}
