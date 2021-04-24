#ifndef CANNON_VIEW_HPP
#define CANNON_VIEW_HPP


#include <list>
#include <memory>

#include "ai_view.hpp"


class Model;
class Actor;
class Cannon;


/**
 * Draw the screen for the player
 */
class CannonView : public AIView {
public:
	CannonView(std::shared_ptr<Model> model, std::shared_ptr<Cannon> cannon);

	bool inRange(std::shared_ptr<Actor> target) override;

	/**
	 * Adjusts cannon angle to point at target
	 *
	 * @param t Target to aim at
	 */
	void aimAt(std::shared_ptr<Actor> t);

	void update(void) override;


private:
	std::shared_ptr<Cannon> cannon;
};


#endif
