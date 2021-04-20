#include <memory>
#include <thread>
#include <chrono>

#include "game_controller.hpp"


int main(int argc, char** argv) {
	std::shared_ptr<GameController> game = std::make_shared<GameController>();
	game->startDemo();

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
