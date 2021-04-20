#include <list>
#include <memory>

#include "view_controller.hpp"
#include "logic_controller.hpp"
#include "view.hpp"
#include "player_view.hpp"
#include "actor.hpp"
#include "pari.hpp"


ViewController::ViewController(std::shared_ptr<GameController> logic) {
	this->logic = logic;
}


void ViewController::reset(void) {}


void ViewController::update(float dt) {
	for (auto view : this->viewList) view->update(dt);
}
