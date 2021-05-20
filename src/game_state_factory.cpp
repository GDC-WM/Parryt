#include <memory>
#include <fstream>

#include "game_state_factory.hpp"
#include "game_state.hpp"

#include "exit.hpp"
#include "platform.hpp"
#include "wall.hpp"
#include "cannon.hpp"
#include "mast.hpp"
#include "grunt.hpp"
#include "cannon_view.hpp"
#include "patrol_ai.hpp"


std::shared_ptr<GameState> GameStateFactory::build(std::string filename) {
	std::shared_ptr<GameState> demo = std::make_shared<GameState>();
	std::ifstream file;
	file.open(filename, std::ios::in);

	std::string line;
	while (file >> line) {
		std::cout << line.substr(0, line.find("="));
	}

	file.close();
	return demo;
}


std::ifstream readSection(std::ifstream file);
