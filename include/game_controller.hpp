#ifndef LOGIC_CONTROLLER_HPP
#define LOGIC_CONTROLLER_HPP


#include <list>
#include <memory>


class GameState;


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
	std::shared_ptr<GameState> getGameState(void) const { return *(this->gameState); };

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


private:
	std::list<std::shared_ptr<GameState>> gameStateList;
	std::list<std::shared_ptr<GameState>>::iterator gameState;
	bool terminated = false;
	bool paused = false;
};


#endif
