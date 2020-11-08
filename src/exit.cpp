#include <list>
#include <memory>

#include "actor.hpp"
#include "exit.hpp"
#include "room.hpp"


Exit::Exit(b2Vec2 position, std::shared_ptr<Exit> destination) : Actor(position) {
	this->destination = destination;
}

Exit::Exit(b2Vec2 position, float width, float height, std::shared_ptr<Exit> destination) : Actor(position) {
	this->destination = destination;
}
