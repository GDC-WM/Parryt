#include <list>
#include <memory>

#include "master_logic.hpp"
#include "master_view.hpp"

#include "room.hpp"
#include "actor.hpp"
#include "exit.hpp"
#include "platform.hpp"
#include "character.hpp"
#include "pari.hpp"


void MasterLogic::init(std::shared_ptr<MasterView> view) {
	this->view = view;
}


void MasterLogic::startDemo(void) {
	// Create room
	this->roomList.push_front(Room());
	this->currentRoom = this->roomList.begin();

	std::shared_ptr<Platform> ground = std::make_shared<Platform>(0, 0, 200);
	this->currentRoom->addActor(ground);

	// Add pari
	std::shared_ptr<Pari> pari = std::make_shared<Pari>(10,2);
	this->currentRoom->addActor(pari);
	this->view->addView(pari);

	// Add Platform
	std::shared_ptr<Platform> platform1 = std::make_shared<Platform>(5, 10, 20);
	this->currentRoom->addActor(platform1);

	// Add Another Platform
	std::shared_ptr<Platform> platform2 = std::make_shared<Platform>(200, 75, 20);
	this->currentRoom->addActor(platform2);
}


void MasterLogic::startMenu(void) {

}


void MasterLogic::reset(void) {
	this->roomList.clear();
	this->currentRoom->reset();
}


void MasterLogic::update(const float &dt) {
	if (!this->paused) {
		// update the room
		this->currentRoom->update(dt);
	}
}
