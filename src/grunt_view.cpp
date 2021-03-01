#include <list>
#include <memory>
#include <cmath>

#include "view.hpp"
#include "grunt_view.hpp"
#include "grunt.hpp"

GruntView::GruntView(std::shared_ptr<LogicController> logic, std::shared_ptr<Grunt> grunt) : AIView(logic, grunt) {
	this->grunt = grunt;
	this->range = 15;
};


void GruntView::update(const float &dt){
	if (this->updateTarget(Allegiance::PARROT)) {
		this->aimAt(this->target);
		this->grunt->shoot();
	}
}

