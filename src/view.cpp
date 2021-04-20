#include "view.hpp"
#include "game_controller.hpp"


View::View(std::shared_ptr<GameController> logic) {
	this->logic = logic;
}
