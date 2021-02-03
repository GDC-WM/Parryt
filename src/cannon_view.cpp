#include <list>
#include <memory>
#include <cmath>

#include "view.hpp"
#include "cannon_view.hpp"
#include "cannon.hpp"


std::list<std::shared_ptr<Actor>> actors;

CannonView::CannonView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Cannon> cannon) : View(logic) {
	this->cannon = cannon;
	this->logic = logic;

	//this->cannon->rotateCounterClockwise();


}


void CannonView::update(const float &dt) {
	this->cannon->shoot();
	actors = this->logic->getCurrentRoom()->getActorList();
	// THIS ORIENTATION IS IN RADIANS!
	
	for (std::shared_ptr<Actor> a : actors) {
			if (a->getAllegiance() == Allegiance::PARROT) {
					b2Vec2 dist = a->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
					this->cannon->barrelAngle = (float) atan2(dist.y, dist.x);
					//float pariAngle = (float) atan2(dist.y, dist.x);

					// make cannon rotate
					/*std::cout << "pari: " << pariAngle << std::endl;
					std::cout << "cannon: " << this->cannon->barrelAngle << std::endl;
					if (pariAngle > this->cannon->barrelAngle) {
							this->cannon->rotateClockwise();
					} else if (pariAngle < this->cannon->barrelAngle) {
							this->cannon->rotateCounterClockwise();
					}*/
			}
	}
}
