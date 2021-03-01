#ifndef CANNON_VIEW_HPP
#define CANNON_VIEW_HPP


#include <list>
#include <memory>

#include "logic_controller.hpp"
#include "view.hpp"
#include "actor.hpp"
#include "cannon.hpp"
#include "ai_view.hpp"


/**
 * Draw the screen for the player
 */
class CannonView : public AIView {
public:
	CannonView(std::shared_ptr<LogicController> logic, std::shared_ptr<Cannon> cannon);

	void update(const float &dt) override;

	
	/**
	 * Adjusts cannon angle to point at target
	 *
	 * @param t Target to aim at
	 */
	void aimAt(std::shared_ptr<Actor> t);


private:
	std::shared_ptr<Cannon> cannon;
};


#endif
