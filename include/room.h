#ifndef ROOM_H
#define ROOM_H

#include <list>
#include <memory>

#include "actor.h"

/*
 * Handles state management between the two rooms and all of the different actor lists
 */
class Room : public std::enable_shared_from_this<Room> {
	private:
		// Actor list
		std::list<std::shared_ptr<Actor>> actorList;

	public:
		Room() {};

		/**
		 * Return the list of actors.
		 */
		std::list<std::shared_ptr<Actor>> getActorList(void) { return this->actorList; };

		void reset(void);
};

#endif
