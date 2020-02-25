#include "master_logic.h"
#include "master_view.h"

#include "actor.h"
#include "room.h"
#include "exit.h"
#include "pari.h"
#include <iostream>

void MasterLogic::init(std::shared_ptr<MasterView> view) {
	this->view = view;
}

void MasterLogic::startDemo(void) {
	this->roomList.clear();

	// Create rooms
	this->roomList.push_front(Room());
	this->currentRoom = roomList.begin();

	// Add pari
	std::shared_ptr<Pari> pari = std::make_shared<Pari>(0,0);
	this->getCurrentRoom().getActorList().push_front(pari);
	this->view->addView(pari);
}

void MasterLogic::startMenu(void) {

}

void MasterLogic::reset(void) {
	this->roomList.clear();

	this->getCurrentRoom().reset();
}

void MasterLogic::update(float dt) {
	if (!this->paused) {
        // Update all actors in the actor list
        if (this->getCurrentRoom().getActorList().size() > 0) {
            for (std::shared_ptr<Actor> actor : this->getCurrentRoom().getActorList()) actor->update(dt);
        }
	}
}
