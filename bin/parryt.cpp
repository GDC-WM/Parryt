#include <memory>
#include <thread>
#include <chrono>

#include "logic_controller.hpp"
#include "view_controller.hpp"
#include "music.hpp"

int main(int argc, char** argv) {
	std::shared_ptr<LogicController> logicController = std::make_shared<LogicController>();
	std::shared_ptr<ViewController> viewController = std::make_shared<ViewController>(logicController);
	logicController->init(viewController);
	logicController->startDemo();

	/* Add Music to demo - This is terrible - I know - but this works for now;
	I would like to add conditionals -- for example, "if this level, then play this music", etc.
	*/
	Sounds ShipMusic("../resources/TestMusic.wav");
	ShipMusic.playTrack();

	// game loop
	std::chrono::steady_clock::time_point startTime;
	while (!logicController->isTerminated()) {
		startTime = std::chrono::steady_clock::now();

		logicController->update(16);
		viewController->update(16);

		auto dt = std::chrono::steady_clock::now() - startTime;
		std::this_thread::sleep_for(std::chrono::milliseconds(16) - dt);
	}

	return 0;
}
	//TODO: separate variable rate graphics loop
