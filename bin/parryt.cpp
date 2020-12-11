#include <memory>
#include <thread>
#include <chrono>

#include "master_logic.hpp"
#include "master_view.hpp"

int main(int argc, char** argv) {
	std::shared_ptr<MasterLogic> logicController = std::make_shared<MasterLogic>();
	std::shared_ptr<MasterView> viewController = std::make_shared<MasterView>(logicController);
	logicController->init(viewController);
	logicController->startDemo();

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
