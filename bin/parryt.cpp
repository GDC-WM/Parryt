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
	std::shared_ptr<Grunt> grunt = std::make_shared<Grunt>(b2Vec2(30, -5), demo->getModel());
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


int main(int argc, char** argv) {
	std::shared_ptr<GameController> game = std::make_shared<GameController>(makeDemo());
	std::shared_ptr<UserView> user = std::make_shared<UserView>(game);
	game->getGameState()->addView(user);

	// game loop
	std::chrono::steady_clock::time_point startTime;
	while (!game->isTerminated()) {
		startTime = std::chrono::steady_clock::now();

		game->update(16);

		auto dt = std::chrono::steady_clock::now() - startTime;
		std::this_thread::sleep_for(std::chrono::milliseconds(16) - dt);
	}

	return 0;
}
	//TODO: separate variable rate graphics loop
