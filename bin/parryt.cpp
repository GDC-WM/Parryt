#include <memory>
#include <thread>
#include <chrono>

#include "game_controller.hpp"
#include "user_view.hpp"
#include "game_state.hpp"


void gameRunner(std::shared_ptr<GameController> game, std::shared_ptr<UserView> user) {
	std::chrono::steady_clock::time_point nextUpdate = std::chrono::steady_clock::now();
	while (user->isRunning()) {
		nextUpdate += std::chrono::milliseconds(16);

		game->isPaused() || game->isInDialogMode()? user->update() : game->update();
		user->drawScreen(); //temporarily put this here until drawing is sorted out

		std::this_thread::sleep_for(nextUpdate - std::chrono::steady_clock::now());
	}
}

int main(int argc, char** argv) {
	std::shared_ptr<GameController> game = std::make_shared<GameController>();
	std::shared_ptr<UserView> user = std::make_shared<UserView>(game);
	game->getGameState()->addView(user);

	gameRunner(game, user);
	//std::thread gameThread(gameRunner, game, user);
	//std::thread drawThread(drawRunner, game, user);
	//gameThread.join();
	//drawThread.join();
	return 0;
}
