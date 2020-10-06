#include <list>
#include <memory>

#include "actor.hpp"
#include "exit.hpp"
#include "room.hpp"


Exit::Exit(double x, double y, std::shared_ptr<Exit> destination) : Actor(x, y) {
	this->destination = destination;
}

Exit::Exit(double x, double y, double width, double height, std::shared_ptr<Exit> destination) : Actor(x, y) {
	this->destination = destination;
}
