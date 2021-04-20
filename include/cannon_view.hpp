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
	CannonView(std::shared_ptr<GameController> logic, std::shared_ptr<Cannon> cannon);

	bool inRange(std::shared_ptr<Actor> target) override;

	/**
	 * Adjusts cannon angle to point at target
	 *
	 * @param t Target to aim at
	 */
	void aimAt(std::shared_ptr<Actor> t);

	void update(const float &dt) override;


private:
	std::shared_ptr<Cannon> cannon;
};


#endif
