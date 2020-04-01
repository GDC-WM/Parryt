#include "master_logic.h"
#include "master_view.h"

#include "actor.h"
#include "room.h"
#include "exit.h"
#include "platform.h"
#include "pari.h"

void MasterLogic::init(std::shared_ptr<MasterView> view) {
	this->view = view;
}

void MasterLogic::startDemo(void) {
	// Create room
	this->roomList.push_front(Room());
	this->currentRoom = this->roomList.begin();

	std::shared_ptr<Platform> ground = std::make_shared<Platform>(0, -100, 20000);
	this->currentRoom->addActor(ground);

	// Add pari
	std::shared_ptr<Pari> pari = std::make_shared<Pari>(300,335);
	this->currentRoom->addActor(pari);
	this->view->addView(pari);

	// Add Platform
	std::shared_ptr<Platform> platform1 = std::make_shared<Platform>(300, 400, 200);
	this->currentRoom->addActor(platform1);

	// Add Another Platform
	std::shared_ptr<Platform> platform2 = std::make_shared<Platform>(700, 400, 200);
	this->currentRoom->addActor(platform2);
}

void MasterLogic::startMenu(void) {

}

void MasterLogic::reset(void) {
	this->roomList.clear();

	this->currentRoom->reset();
}

void MasterLogic::checkCollisions(void) {
	// check if in air or grounded
	for (std::shared_ptr<Actor> actor : this->currentRoom->getActorList()) {
		//if (actor->isPhysical() && actor->) {

		//}
	}
}

void MasterLogic::update(const float &dt) {
	if (!this->paused) {
		// Update all actors in the actor list
		if (this->currentRoom->getActorList().size() > 0) {
			for (std::shared_ptr<Actor> actor : this->currentRoom->getActorList()) actor->update(dt);
			this->checkCollisions();
		}
	}
}
