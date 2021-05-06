#include <memory>
#include <thread>
#include <chrono>

#include "game_controller.hpp"
#include "user_view.hpp"
#include "game_state.hpp"

// remove these later, just here for the demo function:
#include "exit.hpp"
#include "platform.hpp"
#include "wall.hpp"
#include "cannon.hpp"
#include "cannonball.hpp"
#include "mast.hpp"
#include "grunt.hpp"
#include "cannon_view.hpp"
#include "patrol_ai.hpp"


/**
 * Temporary demo method
 */
std::shared_ptr<GameState> makeDemo(void) {
	std::shared_ptr<GameState> demo = std::make_shared<GameState>();

	// add ground
	std::shared_ptr<Platform> ground = std::make_shared<Platform>(b2Vec2(30, -10), 1000);
	demo->addActor(ground);

	// add cannon
	std::shared_ptr<Cannon> cannon = std::make_shared<Cannon>(b2Vec2(15.2,-5), demo->getModel());
	demo->addActor(cannon);
	demo->addView(std::make_shared<CannonView>(demo->getModel(), cannon));

	// Add grunt
	std::shared_ptr<Grunt> grunt = std::make_shared<Grunt>(b2Vec2(100, -5), demo->getModel());
	demo->addActor(grunt);
	demo->addView(std::make_shared<PatrolAI>(demo->getModel(), grunt));

	// Add mast platforms
	for (int i = 0; i < 32; i += 2) {
		demo->addActor(std::make_shared<Platform>(b2Vec2(24.8, -4.8+3.2*i), 3.2));
	}

	// Add Wall
	// std::shared_ptr<Wall> wall1 = std::make_shared<Wall>(b2Vec2(12, 3.8), 3.7);
	// demo->addActor(wall1);

	return demo;
}


void gameUpdate(std::shared_ptr<GameController> game, std::shared_ptr<UserView> user) {
	std::chrono::steady_clock::time_point nextUpdate = std::chrono::steady_clock::now();
	while (user->isRunning()) {
		nextUpdate += std::chrono::milliseconds(16);

		game->isPaused()? user->update() : game->update();
		user->drawScreen(); //temporarily put this here until drawing is sorted out

		std::this_thread::sleep_for(nextUpdate - std::chrono::steady_clock::now());
	}
}


void drawUpdate(std::shared_ptr<GameController> game, std::shared_ptr<UserView> user) {
	while (user->isRunning()) {
		user->drawScreen();
	}
}


int main(int argc, char** argv) {
	std::shared_ptr<GameController> game = std::make_shared<GameController>(makeDemo());
	std::shared_ptr<UserView> user = std::make_shared<UserView>(game);
	game->getGameState()->addView(user);

	std::thread gameThread(gameUpdate, game, user);
	//std::thread drawThread(drawUpdate, game, user);
	gameThread.join();
	//drawThread.join();
	return 0;
}
