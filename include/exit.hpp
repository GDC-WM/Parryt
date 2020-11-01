#ifndef EXIT_HPP
#define EXIT_HPP


#include <memory>

#include "actor.hpp"
#include "room.hpp"


/*
 * Exits to each of the rooms
 */
class Exit : public Actor {
	protected:
		std::shared_ptr<Exit> destination;
		std::shared_ptr<Room> room;

	public:
		Exit(float x, float y, std::shared_ptr<Exit> destination);

		Exit(float x, float y, float width, float height, std::shared_ptr<Exit> destination);

		const std::shared_ptr<Exit> getDestination(void) const { return this->destination; };

		void setDestination(std::shared_ptr<Exit> destination) { this->destination = destination; };

		const std::shared_ptr<Room> getRoom(void) const { return this->room; };

		void setRoom(std::shared_ptr<Room> room) { this->room = room; };
};


#endif
