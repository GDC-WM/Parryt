#include <list>
#include <memory>

#include "master_view.hpp"
#include "master_logic.hpp"
#include "view.hpp"
#include "player_view.hpp"
#include "actor.hpp"
#include "pari.hpp"


MasterView::MasterView(std::shared_ptr<MasterLogic> logic) {
	this->logic = logic;
}


void MasterView::reset(void) {

}


void MasterView::update(float dt) {
	for (auto view : this->viewList) view->update(dt);
}
