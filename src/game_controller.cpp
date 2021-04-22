#include <list>
#include <memory>
#include <box2d/box2d.h>

#include "game_controller.hpp"
#include "game_state.hpp"
#include "model.hpp"


void GameController::reset(void) {
	this->getGameState()->reset();
}


void GameController::update(const float &dt) {
	if (this->getGameState()) this->getGameState()->update(dt);
}
