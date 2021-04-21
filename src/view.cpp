#include "view.hpp"
#include "model.hpp"


View::View(std::shared_ptr<Model> model) {
	this->model = model;
}
