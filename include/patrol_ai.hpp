#ifndef PATROL_AI_HPP
#define PATROL_AI_HPP

#include <list>
#include <memory>

#include "ai_view.hpp"


class Model;
class Actor;
class Grunt;


/**
 * Draw the screen for the player
 */
class PatrolAI : public AIView {
public:
	PatrolAI(std::shared_ptr<Model> model, std::shared_ptr<Grunt> grunt);

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

	void update(void) override;


protected:
	std::shared_ptr<Grunt> grunt;
	b2Vec2 post;
};


#endif
