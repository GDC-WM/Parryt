#ifndef GAME_STATE_FACTORY_HPP
#define GAME_STATE_FACTORY_HPP


#include <memory>

class GameState;


class GameStateFactory {
public:
	GameStateFactory(void) {};

	/**
	 * Build a game state.
	 *
	 * @param filename Name of .ini file to read in.
	 * @return the created game state.
	 */
	std::shared_ptr<GameState> build(std::string filename);

private:
	std::ifstream readSection(std::ifstream file);
};


#endif
