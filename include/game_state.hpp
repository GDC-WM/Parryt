#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP


#include <list>
#include <memory>
#include <box2d/box2d.h>

class Model;
class View;
class Actor;


/*
 * A state of the game (grouping of the views and model)
 */
class GameState : public std::enable_shared_from_this<GameState> {
public:
	GameState(void);

	/**
	 * @return the model
	 */
	const std::shared_ptr<Model> getModel(void) const { return this->model; };

	/**
	 * Add an actor to the model
	 *
	 * @param actor Actor to add
	 */
	void addActor(std::shared_ptr<Actor> actor);

	/**
	 * Remove an Actor from the model
	 *
	 * @param actor actor to remove
	 */
	void removeActor(std::shared_ptr<Actor> actor);

	/**
	 * @return the list of views.
	 */
	const std::list<std::shared_ptr<View>> &getViewList(void) const { return this->viewList; };

	/**
	 * @param view View to add to the view list
	 */
	void addView(std::shared_ptr<View> view) { this->viewList.push_back(view); };

	void reset(void);

	void update(const float &dt);


private:
	std::shared_ptr<Model> model;
	std::list<std::shared_ptr<View>> viewList;
	std::list<std::shared_ptr<View>> viewKillList;
};


#endif
