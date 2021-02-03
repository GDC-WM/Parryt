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


float round2(float var) {
    float value = (int) (var * 100 + .5);
    return (float) value / 100;
}


void CannonView::update(const float &dt) {
	this->cannon->shoot();
	actors = this->logic->getCurrentRoom()->getActorList();
	
	for (std::shared_ptr<Actor> a : actors) {
			if (a->getAllegiance() == Allegiance::PARROT) {
					b2Vec2 dist = a->getBody()->GetPosition() - this->cannon->getBody()->GetPosition();
					float pariAngle = (float) atan2(dist.y, dist.x);

                    std::cout << "pari " << abs(round2(pariAngle)) << std::endl;
                    std::cout << "cannon " << abs(round2(this->cannon->barrelAngle)) << std::endl;
                    if (abs(round2(this->cannon->barrelAngle)) != abs(round2(pariAngle))) {
                        this->cannon->rotateClockwise();
                    } else {
                        this->cannon->rotateStop();
                    }
			}
	}
}
