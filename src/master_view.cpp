#include "master_view.h"
#include "player_view.h"
#include "master_logic.h"

MasterView::MasterView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<sf::RenderWindow> window) {
	this->logic = logic;
	this->window = window;
}

void MasterView::reset(void) {

}

void MasterView::update(float dt) {
}
