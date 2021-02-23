#include <list>
#include <memory>

#include "view.hpp"
#include "cannon_view.hpp"
#include "cannon.hpp"


CannonView::CannonView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Cannon> cannon) : View(logic) {
	this->cannon = cannon;
	this->cannon->rotateClockwise();
}

bool CannonView::targetInRange(std::shared_ptr<Actor> target){
	//true if in range
	//false if not
	//have to aim cannon at target before we can determine if it is in range auuugh
	//aimAt(target)
	//then calculate if in range using arc 
}

void CannonView::aimAt(std::shared_ptr<Actor> t){
	//calculate angle of target's position using trig
	//if cannonAngle != angle
	//	while cannon.cannonAngle < angle, cannon.rotatecounterclockwise()
		//if cannon.cannonangle = angle, stop rotating
		
	// while cannon.cannonAngle > angle, cannon.rotate clockwise
		//if cannon.cannonangle = angle, stop rotating
	//DO WE NEED MARGIN OF ERROR? -> probably wont hti that angle exactly
}

void CannonView::updateTarget(){
	//if no target: all this
	std::list<std::shared_ptr<Actor>> actors = this->cannon->getRoom()->getActorList();
	for(std::shared_ptr<Actor> a : actors){
		if(a->getAllegiance() == Allegiance::PARROT && a->isTarget() && this->targetInRange(a)){
			this->target = a;
		}
	}
}


void CannonView::update(const float &dt) {
	
	this->cannon->shoot();
}
