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

	bool updateTarget(const Allegiance allegiance);

	/**
	 * Aims at the target
	 * 
	 */
	void aimAt();


	/**
	 * Chases the target
	 */
	void chase();


	/**
	 * Ambient movement (patrolling)
	 * @param post the grunt's area of patrol
	 */
	void patrol(b2Vec2 post);
	

protected:
    std::shared_ptr<Grunt> grunt;
	bool facingTarget; //if facing the target and target in range, aggro
						//if it's not facing the target, only aggro if target is in the patrol zone	
};



#endif