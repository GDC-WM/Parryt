#ifndef LOGIC_CONTROLLER_HPP
#define LOGIC_CONTROLLER_HPP


#include <list>
#include <memory>


class GameState;


/**
 * Main logic class that controls everything.
 */
class GameController {
public:
	/**
	 * Main method
	 */
	GameController(void) {};

	/**
	 * Main method
	 */
	GameController(std::shared_ptr<GameState> state) { this->setGameState(state); };

	/**
	 *
	 */
	std::shared_ptr<GameState> getGameState(void) const { return this->gameState; };

	/**
	 *
	 */
	void setGameState(std::shared_ptr<GameState> state) { this->gameState = state; };

	/**
	 * Resets game controller to default
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
	std::shared_ptr<GameState> gameState;
	bool terminated = false;
	bool paused = false;
};


#endif
