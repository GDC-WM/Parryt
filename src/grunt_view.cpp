#include <list>
#include <memory>
#include <cmath>

#include "view.hpp"
#include "grunt_view.hpp"
#include "grunt.hpp"

GruntView::GruntView(std::shared_ptr<LogicController> logic, std::shared_ptr<Grunt> grunt) : AIView(logic, grunt) {
	this->grunt = grunt;
	this->range = 10;
};


void GruntView::aimAt(){
	//pew pew
	//theres not really anything to rotate, calculate angle to shoot bullet at?
	//or just do that in the shoot method? girl idk girl
	//calculate angle of target's position using trig
	b2Vec2 targetDist = this->target->getBody()->GetPosition() - this->grunt->getBody()->GetPosition();
	float targetAngle = atan2(targetDist.y, targetDist.x);
	this->grunt->setGunAngle(targetAngle);
	this->grunt->shoot();
}

bool GruntView::updateTarget(const Allegiance allegiance){
	b2Vec2 dangerZone = b2Vec2(2, 2);
	std::list<std::shared_ptr<Actor>> actors = this->actor->getRoom()->getActorList();
	for (std::shared_ptr<Actor> a : actors){
		if (a->getAllegiance() == allegiance && a->isTargetable()){
			if(this->inRange(a)){
				if(a->getBody()->GetPosition().x < this->grunt->getBody()->GetPosition().x){ 
					if(this->grunt->getDirection() == Direction::LEFT){
						//looking at it
						this->target = a;
						return true;
					}
					//grunt is looking left & a is to its right
					b2Vec2 difference = a->getBody()->GetPosition()-this->grunt->getBody()->GetPosition();
					if(difference.x<=dangerZone.x && difference.y<=dangerZone.y){ //if it's within 2
						this->target =a;
						return true;
					}
				}
				if(a->getBody()->GetPosition().x > this->grunt->getBody()->GetPosition().x){ 
					if(this->grunt->getDirection() == Direction::RIGHT){
						//looking at it to the right
						this->target =a;
						return true;
					}
					//grunt is looking left & a is to its right
					b2Vec2 difference = a->getBody()->GetPosition()-this->grunt->getBody()->GetPosition();
					if(difference.x<=dangerZone.x && difference.y<=dangerZone.y){ //if it's within 2meters
						this->target =a;
						return true;
					}
				}

			}
		}
	}
	this->target = NULL;
	return false;	
}

void GruntView::patrol(b2Vec2 post){
	int leftLim = post.x; //8 is arbitrary
	int rightLim = post.x +8;

	if(this->grunt->getDirection() == Direction::LEFT){
		if(this->grunt->getBody()->GetPosition().x <= leftLim){
			//std::cout<<" hit left limit, going right now ";
			this->grunt->goRight();
		}else{
			//std::cout<<" facing left going left ";
			this->grunt->goLeft();
		}
	}
	if(this->grunt->getDirection() == Direction::RIGHT){
		if(this->grunt->getBody()->GetPosition().x >= rightLim){
			//std::cout<<" hit right lim going left now ";
			this->grunt->goLeft();
		}else{
			//std::cout<<" facing right going right ";
			this->grunt->goRight();
		}
	}
}


void GruntView::chase(){
	if(this->target->getBody()->GetPosition().x < this->grunt->getBody()->GetPosition().x){
		//target is to the left
		this->grunt->goLeft();
	}
	if(this->target->getBody()->GetPosition().x > this->grunt->getBody()->GetPosition().x ){
		//target is to the right
		this->grunt->goRight();
	}
	if(this->target->getBody()->GetPosition().y > this->grunt->getBody()->GetPosition().y){
		//target is above pirate
		this->grunt->jump(); 

		//aaron is cool ig
	}
	
}


void GruntView::update(const float &dt){
	if (this->updateTarget(Allegiance::PARROT)){
		this->chase();
		this->aimAt();
	}else{
		this->patrol(this->grunt->getPost());
	}
}

