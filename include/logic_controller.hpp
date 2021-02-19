#ifndef LOGIC_CONTROLLER_HPP
#define LOGIC_CONTROLLER_HPP


#include <list>
#include <memory>

class ViewController;

#include "room.hpp"
#include "actor.hpp"
#include "exit.hpp"
#include "platform.hpp"
#include "character.hpp"
#include "pari.hpp"


/**
 * Main logic class that controls everything.
 */
class LogicController {
public:
	/**
	 * Main method
	 */
	LogicController(void) { };

	/**
	 *
	 */
	void init(std::shared_ptr<ViewController> mv);

	/**
	 * Start main menu
	 */
	void startMenu(void);

	/**
	 * Start a demo of gameplay
	 */
	void startDemo(void);

	/**
	 *
	 */
	std::shared_ptr<Room> getCurrentRoom(void) const { return *(this->currentRoom); };

	/**
	 * Resets master logic to default state
	 */
	void reset(void);

	/**
	 * Terminate the application?
	 */
	bool isTerminated(void) { return this->terminated; };

	/**
	 * Terminate the application
	 */
	void terminate(void) { this->terminated = true; };

	/**
	 *
	 */
	void update(const float &dt);

	sf::Event event;


private:
	std::shared_ptr<ViewController> view;
	std::list<std::shared_ptr<Room>> roomList;
	std::list<std::shared_ptr<Room>>::iterator currentRoom;
	bool terminated = false;
	bool paused = false;
};


#endif
