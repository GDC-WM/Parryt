#include "master_view.hpp"
#include "player_view.hpp"
#include "master_logic.hpp"

MasterView::MasterView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<sf::RenderWindow> window) {
	this->logic = logic;
	this->window = window;
}

void MasterView::reset(void) {

}

void MasterView::update(float dt) {
	for (auto view : this->viewList) view->update(dt);
}
