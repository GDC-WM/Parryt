#include <list>
#include <memory>
#include <cmath>

#include "view.hpp"
#include "grunt_view.hpp"
#include "grunt.hpp"

GruntView::GruntView(std::shared_ptr<LogicController> logic, std::shared_ptr<Grunt> grunt) : AIView(logic, grunt) {
	this->grunt = grunt;
	this->range = 15;
};


void GruntView::aimAt(){
	//auuugh
}

bool GruntView::updateTarget(const Allegiance allegiance){
	b2Vec2 dangerZone = b2Vec2(5, 5);
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
	int leftLim = post.x; //8 is arbitrary, he will patrol within 8 ft left and 8 ft right of his post
	int rightLim = post.x +16;

	if(this->grunt->getDirection() == Direction::LEFT){
		if(this->grunt->getBody()->GetPosition().x <= leftLim){
			this->grunt->goRight();
		}
		this->grunt->goLeft();
	}
	if(this->grunt->getDirection() == Direction::RIGHT){
		if(this->grunt->getBody()->GetPosition().x >= rightLim){
			this->grunt->goLeft();
		}
		this->grunt->goRight();
	}
}


void GruntView::chase(){
	if(this->target->getBody()->GetPosition().x < this->grunt->getBody()->GetPosition().x){
		//target is to the left
		this->grunt->goLeft();
	}
	if(this->target->getBody()->GetPosition().x > this->grunt->getBody()->GetPosition().x){
		//target is to the right
		this->grunt->goRight();
	}
	if(this->target->getBody()->GetPosition().y > this->grunt->getBody()->GetPosition().y){
		//target is above pirate
		this->grunt->jump(); //lol why doesn't he fall???

		//aaron is cool ig
	}
	
}


void GruntView::update(const float &dt){
	if (this->updateTarget(Allegiance::PARROT)){
		this->chase();
		this->aimAt();
		this->grunt->shoot();
	}
	this->patrol(this->grunt->getPost());
}

