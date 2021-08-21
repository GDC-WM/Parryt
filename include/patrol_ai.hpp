#ifndef PATROL_AI_HPP
#define PATROL_AI_HPP

#include <list>
#include <memory>

#include "ai_view.hpp"
#include "dialog.hpp"

class Model;
class Actor;
class Grunt;
class Dialog;


/**
 * Draw the screen for the player
 */
class PatrolAI : public AIView {
public:
	PatrolAI(std::shared_ptr<Model> model, std::shared_ptr<Grunt> grunt, b2Vec2 post, int patrolRange);

	bool updateTarget(const glob::Allegiance allegiance);

	/**
	 * Aims at the target
	 *
	 */
	void aimAt(void);

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
	//std::shared_ptr<DialogSystem> dialog;
	std::shared_ptr<sf::RenderWindow> window;
	b2Vec2 post;
	int patrolRange;
};


#endif
