#ifndef LOGIC_CONTROLLER_HPP
#define LOGIC_CONTROLLER_HPP


#include <list>
#include <memory>

#include "room.hpp"
#include "view.hpp"
#include "user_view.hpp"
#include "actor.hpp"
#include "exit.hpp"
#include "platform.hpp"
#include "character.hpp"
#include "pari.hpp"


/**
 * Main logic class that controls everything.
 */
class GameController : public std::enable_shared_from_this<GameController> {
public:
	/**
	 * Main method
	 */
	GameController(void) {};

	/**
	 * Start main menu
	 */
	void startMenu(void);

	// TODO: add a method for reading a file for a level and possibly remove the following method
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
	std::list<std::shared_ptr<Room>> roomList;
	std::list<std::shared_ptr<Room>>::iterator currentRoom;
	std::shared_ptr<UserView> userView;
	bool terminated = false;
	bool paused = false;
};


#endif
