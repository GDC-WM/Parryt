#ifndef ROOM_H
#define ROOM_H


#include <list>
#include <memory>

#include "box2d/box2d.h"
#include "actor.hpp"


/*
 * Handles state management between the two rooms and all of the different actor lists
 */
class Room : public std::enable_shared_from_this<Room> {
	private:
		// Actor list
		std::shared_ptr<b2World> world;
		std::list<std::shared_ptr<Actor>> actorList;

	public:
		Room(void);

		/**
		 * Return the list of actors.
		 */
		const std::list<std::shared_ptr<Actor>> &getActorList(void) const { return this->actorList; };

		/**
		 * Add an actor to the list
		 *
		 * actor -- actor to add
		 */
		void addActor(std::shared_ptr<Actor> actor);

		void reset(void);

		void update(const float &dt);

};


#endif
