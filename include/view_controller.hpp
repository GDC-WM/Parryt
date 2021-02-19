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


/**
 * Manages all of the different views and game states
 */
class ViewController {
public:
	ViewController(std::shared_ptr<LogicController> logic);

	void reset();

	/**
	 * Add PlayerView
	 */
	void addView(std::shared_ptr<Pari> a) { this->viewList.push_back(std::make_shared<PlayerView>(this->logic, a)); };

	/**
	 * Add CannonView
	 */
	void addView(std::shared_ptr<Cannon> a) { this->viewList.push_back(std::make_shared<CannonView>(this->logic, a)); };

	/**
	 * Create a view for the new enemy from logic and add the view to the enemyview list
	 */
	void update(float dt);


private:
	std::shared_ptr<LogicController> logic;
	std::list<std::shared_ptr<View>> viewList;
};


#endif
