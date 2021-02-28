#ifndef ENEMY_VIEW_HPP
#define ENEMY_VIEW_HPP

#include <list>
#include <memory>

#include "logic_controller.hpp"
#include "view.hpp"
#include "character.hpp"
#include "enemy.hpp"

/**
 * Draw the screen for the player
 */
class EnemyView : public View {
public:
	EnemyView(std::shared_ptr<LogicController> logic, std::shared_ptr<Enemy> enemy);

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
    std::shared_ptr<Enemy> enemy;
    std::shared_ptr<LogicController> logic;
	std::shared_ptr<Actor> target;
};



#endif