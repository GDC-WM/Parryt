#include <list>
#include <memory>
#include <cmath>

#include "patrol_ai.hpp"
#include "model.hpp"
#include "grunt.hpp"


PatrolAI::PatrolAI(std::shared_ptr<Model> model, std::shared_ptr<Grunt> grunt) : AIView(model, grunt) {
	this->model = model;
	this->grunt = grunt;
	this->range = 20;
}


void PatrolAI::aimAt() {
	//so why doesn't he shoot to the left...
	b2Vec2 targetDist = this->target->getBody()->GetPosition() - this->grunt->getBody()->GetPosition();
	float targetAngle = atan2(targetDist.y, targetDist.x); //returns radians
	this->grunt->setShootDir(targetDist);
	this->grunt->shoot();
}


bool PatrolAI::updateTarget(const Allegiance allegiance) {
	b2Vec2 dangerZone = b2Vec2(2, 2);
	for (std::shared_ptr<Actor> a : this->model->getActorList()) {
		if (!(a->getAllegiance() == allegiance
		   && a->isTargetable()
		   && this->inRange(a)))
			continue;

		if (a->getBody()->GetPosition().x < this->grunt->getBody()->GetPosition().x) {
			if (this->grunt->getMovement() == Dir::left) {
				//looking at it
				this->target = a;
				return true;
			}
			//grunt is looking left & a is to its right
			b2Vec2 difference = a->getBody()->GetPosition() - this->grunt->getBody()->GetPosition();
			if (difference.x <= dangerZone.x && difference.y <= dangerZone.y) { //if it's within 2
				this->target = a;
				return true;
			}
		}

		if (a->getBody()->GetPosition().x > this->grunt->getBody()->GetPosition().x) {
			if (this->grunt->getLookDir() == Dir::right) {
				//looking at it to the right
				this->target = a;
				return true;
			}
			//grunt is looking left & a is to its right
			b2Vec2 difference = a->getBody()->GetPosition() - this->grunt->getBody()->GetPosition();
			if (difference.x <= dangerZone.x && difference.y <= dangerZone.y) { //if it's within 2meters
				this->target = a;
				return true;
			}
		}
	}
	this->target = NULL;
	return false;
}


void PatrolAI::patrol(void) {
	int leftLim = post.x; // 8 is arbitrary
	int rightLim = post.x + 8;

	//this->grunt->setMovement(Dir::left);

	if (this->grunt->getBody()->GetPosition().x >= rightLim) {
		//std::cout<<" hit right lim going left now ";
		this->grunt->setMovement(Dir::left);
	}
	if (this->grunt->getBody()->GetPosition().x <= leftLim) {
		this->grunt->setMovement(Dir::right);
	}
}


void PatrolAI::chase() {
	if (this->target->getBody()->GetPosition().x < this->grunt->getBody()->GetPosition().x) {
		//target is to the left
		this->grunt->setMovement(Dir::left);
	}
	if (this->target->getBody()->GetPosition().x > this->grunt->getBody()->GetPosition().x) {
		//target is to the right
		//std::cout<<"going right chasing";
		this->grunt->setMovement(Dir::right);
	}
	if (this->target->getBody()->GetPosition().y > this->grunt->getBody()->GetPosition().y) {
		//target is above pirate
		this->grunt->jump();
	}
}


void PatrolAI::update(const float &dt) {
	if (this->updateTarget(Allegiance::parrot)) {
		this->chase();
		this->aimAt();
	} else {
		this->patrol();
	}
}

