#include <list>
#include <memory>

#include "logic_controller.hpp"
#include "view_controller.hpp"

#include "room.hpp"
#include "actor.hpp"
#include "exit.hpp"
#include "platform.hpp"
#include "wall.hpp"
#include "character.hpp"
#include "pari.hpp"
#include "cannon.hpp"
#include "cannonball.hpp"
#include "mast.hpp"


void LogicController::init(std::shared_ptr<ViewController> view) {
	this->view = view;
}


void LogicController::startDemo(void) {
	// Create room
	this->roomList.push_front(std::make_shared<Room>());
	this->currentRoom = this->roomList.begin();

	// Add ground
	std::shared_ptr<Platform> ground = std::make_shared<Platform>(b2Vec2(30, -10), 1000);
	this->getCurrentRoom()->addActor(ground);

	// Add pari
	std::shared_ptr<Pari> pari = std::make_shared<Pari>(b2Vec2(-13,-5));
	this->getCurrentRoom()->addActor(pari);
	this->view->addView(pari);

	// Add cannon
	std::shared_ptr<Cannon> cannon = std::make_shared<Cannon>(b2Vec2(15.2,-5));
	this->getCurrentRoom()->addActor(cannon);
	this->view->addView(cannon);

	// Add mast platforms
	for(int i = 0; i < 32; i += 2) {
		this->getCurrentRoom()->addActor(std::make_shared<Platform>(b2Vec2(24.8, -4.8+3.2*i), 3.2));
	}
	// Add Platform
	// std::shared_ptr<Platform> platform1 = std::make_shared<Platform>(b2Vec2(31.9, 7.5), 20);
	// this->getCurrentRoom()->addActor(platform1);

	// Add Wall
	// std::shared_ptr<Wall> wall1 = std::make_shared<Wall>(b2Vec2(12, 3.8), 3.7);
	// this->getCurrentRoom()->addActor(wall1);
}


void LogicController::startMenu(void) {

}


void LogicController::reset(void) {
	this->roomList.clear();
	this->getCurrentRoom()->reset();
}


void LogicController::update(const float &dt) {
	if (!this->paused) {
		// update the room
		this->getCurrentRoom()->update(dt);
	}
}
