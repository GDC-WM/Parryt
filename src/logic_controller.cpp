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
#include "grunt.hpp"


void LogicController::init(std::shared_ptr<ViewController> view) {
	this->viewController = view;
}


void LogicController::startDemo(void) {
	// create room
	this->roomList.push_front(std::make_shared<Room>());
	this->currentRoom = this->roomList.begin();

	// add ground
	std::shared_ptr<Platform> ground = std::make_shared<Platform>(b2Vec2(30, -10), 1000);
	this->getCurrentRoom()->addActor(ground);

	// add pari
	std::shared_ptr<Pari> pari = std::make_shared<Pari>(b2Vec2(-13,-5));
	this->getCurrentRoom()->addActor(pari);
	this->viewController->addView(std::make_shared<PlayerView>(this->shared_from_this(), pari));

	// add cannon
	std::shared_ptr<Cannon> cannon = std::make_shared<Cannon>(b2Vec2(15.2,-5));
	this->getCurrentRoom()->addActor(cannon);
	this->viewController->addView(std::make_shared<CannonView>(this->shared_from_this(), cannon));

	// Add grunt
	std::shared_ptr<Grunt> grunt = std::make_shared<Grunt>(b2Vec2(30, -5));
	this->getCurrentRoom()->addActor(grunt);
	this->viewController->addView(std::make_shared<GruntView>(this->shared_from_this(), grunt));

	// Add mast platforms
	for (int i = 0; i < 32; i += 2) {
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
	// will start the main menu screen of game
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
