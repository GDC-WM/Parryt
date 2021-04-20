#ifndef AI_VIEW_HPP
#define AI_VIEW_HPP


#include <list>
#include <memory>

#include "view.hpp"
#include "character.hpp"


class AIView : public View {
public:
	AIView(std::shared_ptr<Room> room, std::shared_ptr<Actor> actor);

	/**
	 * Checks if specified target is in range of AI
	 *
	 * @return if target is out of range
	 * @param target Target to be checked
	 */
	virtual bool inRange(std::shared_ptr<Actor> target);

	/**
	 * Set target to a new one within range
	 *
	 * @param allegiance the allegiance that the target should be
	 * @return True if found a target, false if not
	 */
	bool updateTarget(const Allegiance allegiance);

	/**
	 * Attacks the current target
	 */
	//void attack();

	virtual void update(const float &dt) {};


protected:
	int range;
	std::shared_ptr<Actor> actor;
	std::shared_ptr<Actor> target;
	std::shared_ptr<GameController> logic;
};


#endif
