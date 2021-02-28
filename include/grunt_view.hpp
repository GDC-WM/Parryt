#ifndef GRUNT_VIEW_HPP
#define GRUNT_VIEW_HPP

#include <list>
#include <memory>

#include "logic_controller.hpp"
#include "view.hpp"
#include "character.hpp"
#include "grunt.hpp"

/**
 * Draw the screen for the player
 */
class GruntView : public View {
public:
	GruntView(std::shared_ptr<LogicController> logic, std::shared_ptr<Grunt> grunt);

	void update(const float &dt) override;

	/**
	 * @return if target is out of range
	 * @param actor Target to be checked
	 */
	bool inRange(std::shared_ptr<Actor> actor);

	/**
	 * Update target if no target or if target out of range
	 *
	 * @return True if found a target, false if not
	 */
	bool updateTarget(void);

	

protected:
    std::shared_ptr<Grunt> grunt;
    std::shared_ptr<LogicController> logic;
	std::shared_ptr<Actor> target;
};



#endif