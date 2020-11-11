#include <list>
#include <memory>

#include "view.hpp"
#include "cannon_view.hpp"
#include "cannon.hpp"


CannonView::CannonView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Cannon> cannon) : View(logic) {
	this->cannon = cannon;
}

void CannonView::update(const float &dt) {
	this->cannon->shoot();
}
