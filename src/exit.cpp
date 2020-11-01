#include <list>
#include <memory>

#include "actor.hpp"
#include "exit.hpp"
#include "room.hpp"


Exit::Exit(float x, float y, std::shared_ptr<Exit> destination) : Actor(x, y) {
	this->destination = destination;
}

Exit::Exit(float x, float y, float width, float height, std::shared_ptr<Exit> destination) : Actor(x, y) {
	this->destination = destination;
}
