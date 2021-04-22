#include <list>
#include <memory>
#include <box2d/box2d.h>

#include "game_state.hpp"
#include "model.hpp"
#include "view.hpp"


GameState::GameState(void) {
	this->model = std::make_shared<Model>();
}


void GameState::reset(void) {
	this->model->reset();
}


void GameState::update(const float &dt) {
	this->model->update(dt);

	// update all views in the view list
	if (this->viewList.size() > 0) {
		for (std::shared_ptr<View> view : this->viewList) view->update(dt);
	}
	// TODO: kill marked views
}
