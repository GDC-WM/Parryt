#ifndef GRUNT_VIEW_HPP
#define GRUNT_VIEW_HPP

#include <list>
#include <memory>

#include "logic_controller.hpp"
#include "view.hpp"
#include "character.hpp"
#include "grunt.hpp"
#include "ai_view.hpp"

/**
 * Draw the screen for the player
 */
class GruntView : public AIView {
public:
	GruntView(std::shared_ptr<LogicController> logic, std::shared_ptr<Grunt> grunt);

	void update(const float &dt) override;

	/**
	 * Aims at a target
	 * @param target the target to aim at
	 */
	void aimAt(std::shared_ptr<Actor> target){};
	

protected:
    std::shared_ptr<Grunt> grunt;	
};



#endif