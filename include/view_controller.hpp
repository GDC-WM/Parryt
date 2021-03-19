#ifndef VIEW_CONTROLLER_HPP
#define VIEW_CONTROLLER_HPP


#include <list>
#include <memory>

#include "logic_controller.hpp"
#include "view.hpp"
#include "player_view.hpp"
#include "actor.hpp"
#include "pari.hpp"
#include "cannon.hpp"
#include "cannon_view.hpp"
#include "grunt_view.hpp"
#include "grunt.hpp"


/**
 * Manages all of the views and game states.
 */
class ViewController {
public:
	ViewController(std::shared_ptr<LogicController> logic);

	void reset();

	/**
	 * @param view View to add to the view list
	 */
	void addView(std::shared_ptr<View> view) { this->viewList.push_back(view); };

	/**
	 * Update each view.
	 *
	 * @param dt length of time to progress for this update
	 */
	void update(float dt);


private:
	std::shared_ptr<LogicController> logic;
	std::list<std::shared_ptr<View>> viewList;
};


#endif
