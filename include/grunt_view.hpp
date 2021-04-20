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
class PatrolAI : public AIView {
public:
	PatrolAI(std::shared_ptr<GameController> logic, std::shared_ptr<Grunt> grunt);

	bool updateTarget(const Allegiance allegiance);

	/**
	 * Aims at the target
	 *
	 */
	void aimAt(void);

	/**
	 * gives the grunt a post to patrol
	 * @param post the coordinates of the center of their post
	 */
	void setPost(const b2Vec2 &post) { this->post = post; };

	/**
	 * Chases the target
	 */
	void chase(void);

	/**
	 * Ambient movement (patrolling)
	 * @param post the grunt's area of patrol
	 */
	void patrol(void);

	void update(const float &dt) override;


protected:
	std::shared_ptr<Grunt> grunt;
	b2Vec2 post;
};


#endif
