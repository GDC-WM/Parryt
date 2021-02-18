#include <list>
#include <memory>

#include "view.hpp"
#include "cannon_view.hpp"
#include "cannon.hpp"


CannonView::CannonView(std::shared_ptr<LogicController> logic, std::shared_ptr<Cannon> cannon) : View(logic) {
	this->cannon = cannon;
	this->cannon->rotateClockwise();
}

bool CannonView::targetInRange(std::shared_ptr<Actor> target){
	//true if in range
	//false if not
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
