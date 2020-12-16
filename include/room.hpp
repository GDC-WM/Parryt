#ifndef ROOM_HPP
#define ROOM_HPP


#include <list>
#include <memory>
#include <box2d/box2d.h>

class Actor;


/*
 * Handles state management between the two rooms and all of the different actor lists
 */
class Room : public std::enable_shared_from_this<Room> {
	public:
		Room(void);

		/**
		 * Return the world
		 */
		const std::shared_ptr<b2World> getWorld(void) const { return this->world; };

		/**
		 * Return the list of actors.
		 */
		const std::list<std::shared_ptr<Actor>> &getActorList(void) const { return this->actorList; };

		/**
		 * Add an actor to the list
		 *
		 * @param actor actor to add
		 */
		void addActor(std::shared_ptr<Actor> actor);

		/**
		 * Remove an actor from the list
		 *
		 * @param actor actor to remove
		 */
		void removeActor(std::shared_ptr<Actor> actor);

		void reset(void);

		void update(const float &dt);


	private:
		// Actor list
		std::shared_ptr<b2World> world;
		std::list<std::shared_ptr<Actor>> actorList;
};


#endif
