#ifndef EXIT_H
#define EXIT_H

#include <memory>

#include "actor.h"
#include "room.h"

/*
 * Exits to each of the rooms
 */
class Exit : public Actor {
	protected:
		std::shared_ptr<Exit> destination;
		std::shared_ptr<Room> room;

	public:
		Exit(double x, double y, std::shared_ptr<Exit> destination);

		Exit(double x, double y, double width, double height, std::shared_ptr<Exit> destination);

		std::shared_ptr<Exit> getDestination(void) { return this->destination; };

		void setDestination(std::shared_ptr<Exit> destination) { this->destination = destination; };

		std::shared_ptr<Room> getRoom(void) { return this->room; };

		void setRoom(std::shared_ptr<Room> room) { this->room = room; };
};

#endif
