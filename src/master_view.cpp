#include "master_view.h"
#include "master_logic.h"
#include <iostream>

MasterView::MasterView(std::shared_ptr<sf::RenderWindow> window) {
	this->window = window;
}

void MasterView::init(std::shared_ptr<MasterLogic> logic) {
	this->logic = logic;
}

void MasterView::reset(void) {
	this->enemies.clear();
	this->rangeEnemies.clear();
}

void MasterView::update(float delta) {

}
