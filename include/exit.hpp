#ifndef EXIT_HPP
#define EXIT_HPP


#include <memory>

#include "actor.hpp"


class GameState;


/*
 * Exits to each of the rooms
 */
class Exit : public Actor {
public:
	Exit(b2Vec2 position, std::shared_ptr<Exit> destination);

	Exit(b2Vec2 position, float width, float height, std::shared_ptr<Exit> destination);

	const std::shared_ptr<Exit> getDestination(void) const { return this->destination; };

	void setDestination(std::shared_ptr<Exit> destination) { this->destination = destination; };

	const std::shared_ptr<GameState> getRoom(void) const { return this->room; };

	void setRoom(std::shared_ptr<GameState> room) { this->room = room; };


protected:
	std::shared_ptr<Exit> destination;
	std::shared_ptr<GameState> room;
};


#endif
