#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP


#include <list>
#include <memory>
#include <box2d/box2d.h>

#include "contact_filter.hpp"
#include "contact_listener.hpp"
#include "view.hpp"
#include "actor.hpp"


/*
 * A physical space containing a list of all of the actors
 */
class GameState : public std::enable_shared_from_this<GameState> {
public:
	GameState(void);

	/**
	 * Return the world
	 */
	const std::shared_ptr<b2World> getWorld(void) const { return this->world; };

	/**
	 * Return the list of actors.
	 */
	const std::list<std::shared_ptr<Actor>> &getActorList(void) const { return this->actorList; };

	/**
	 * Return the list of views.
	 */
	const std::list<std::shared_ptr<View>> &getViewList(void) const { return this->viewList; };

	/**
	 * Add an actor to the list
	 *
	 * @param actor Actor to add
	 */
	void addActor(std::shared_ptr<Actor> actor);

	/**
	 * Remove an Actor from the list
	 *
	 * @param actor actor to remove
	 */
	void removeActor(std::shared_ptr<Actor> actor);

	/**
	 * @param view View to add to the view list
	 */
	void addView(std::shared_ptr<View> view) { this->viewList.push_back(view); };

	void reset(void);

	void update(const float &dt);


private:
	// Actor list
	std::shared_ptr<b2World> world;
	std::list<std::shared_ptr<Actor>> actorList;
	std::list<std::shared_ptr<Actor>> actorKillList;
	std::list<std::shared_ptr<View>> viewList;
	ContactFilter contact_filter;
	ContactListener contact_listener;
};


#endif
