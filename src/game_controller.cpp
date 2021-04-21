#include <list>
#include <memory>

#include "game_controller.hpp"
#include "game_state.hpp"

#include "exit.hpp"
#include "platform.hpp"
#include "wall.hpp"
#include "pari.hpp"
#include "cannon.hpp"
#include "cannonball.hpp"
#include "mast.hpp"
#include "grunt.hpp"
#include "user_view.hpp"
#include "cannon_view.hpp"
#include "grunt_view.hpp"
#include "patrol_ai.hpp"


void GameController::startDemo(void) {
	// create room
	this->gameStateList.push_front(std::make_shared<GameState>());
	this->gameState = this->gameStateList.begin();

	// add ground
	std::shared_ptr<Platform> ground = std::make_shared<Platform>(b2Vec2(30, -10), 1000);
	this->getGameState()->addActor(ground);

	// add pari
	std::shared_ptr<Pari> pari = std::make_shared<Pari>(b2Vec2(-13,-5));
	this->getGameState()->addActor(pari);
	this->userView = std::make_shared<UserView>(this->shared_from_this(), pari);
	this->getGameState()->addView(this->userView);

	// add cannon
	std::shared_ptr<Cannon> cannon = std::make_shared<Cannon>(b2Vec2(15.2,-5));
	this->getGameState()->addActor(cannon);
	this->getGameState()->addView(std::make_shared<CannonView>(this->shared_from_this(), cannon));

	// Add grunt
	std::shared_ptr<Grunt> grunt = std::make_shared<Grunt>(b2Vec2(30, -5));
	this->getGameState()->addActor(grunt);
	this->getGameState()->addView(std::make_shared<PatrolAI>(this->shared_from_this(), grunt));

	// Add mast platforms
	for (int i = 0; i < 32; i += 2) {
		this->getGameState()->addActor(std::make_shared<Platform>(b2Vec2(24.8, -4.8+3.2*i), 3.2));
	}

	// Add Platform
	// std::shared_ptr<Platform> platform1 = std::make_shared<Platform>(b2Vec2(31.9, 7.5), 20);
	// this->getGameState()->addActor(platform1);

	// Add Wall
	// std::shared_ptr<Wall> wall1 = std::make_shared<Wall>(b2Vec2(12, 3.8), 3.7);
	// this->getGameState()->addActor(wall1);
}


void GameController::startMenu(void) {
	// will start the main menu screen of game
}


void GameController::reset(void) {
	this->gameStateList.clear();
	this->getGameState()->reset();
}


void GameController::update(const float &dt) {
	this->getGameState()->update(dt);
}
