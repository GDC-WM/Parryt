#include <list>
#include <memory>
#include <cmath>

#include "view.hpp"
#include "grunt_view.hpp"
#include "grunt.hpp"

GruntView::GruntView(std::shared_ptr<LogicController> logic, std::shared_ptr<Grunt> grunt) : View(logic) {
	this->grunt = grunt;
	this->logic = logic;
};