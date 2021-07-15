#include <memory>
#include <vector>
#include <unordered_map>
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
#include "barrel.hpp"
#include "mast.hpp"

std::unordered_map<std::string, std::vector<std::string>> tokenize(std::ifstream &file) {
	std::unordered_map<std::string, std::vector<std::string>> tokens;

	std::string line;
	while (getline(file, line) && !line.empty()) {
		int start = 0;
		int end = line.find("=");
		std::string key = line.substr(start, end - start);

		std::vector<std::string> values;
		while (end != -1) {
			start = end + 1;
			end = line.find(",", start);
			values.push_back(line.substr(start, end - start));
		}

		tokens[key] = values;
	}
	return tokens;
}


std::shared_ptr<GameState> GameStateFactory::build(std::string filename) {
	std::shared_ptr<GameState> demo = std::make_shared<GameState>();
	std::ifstream file;
	file.open(filename, std::ios::in);

	std::string line;
	while (getline(file, line)) {
		if (line.at(0) == '[') {
			std::string header = line.substr(1, line.find(']') - 1);
			auto tokens = tokenize(file);
			if (header == "platform") {
				std::vector<std::string> pos = tokens["pos"];
				demo->addActor(std::make_shared<Platform>(b2Vec2(stoi(pos[0]), stoi(pos[1])), stoi(tokens["width"][0])));
			}
			else if (header == "cannon/cannonai") {
				std::vector<std::string> pos = tokens["pos"];
				auto actor = std::make_shared<Cannon>(b2Vec2(stoi(pos[0]), stoi(pos[1])), demo->getModel());
				demo->addActor(actor);
				demo->addView(std::make_shared<CannonView>(demo->getModel(), actor));
			}
			else if (header == "grunt/patrolai") {
				std::vector<std::string> pos = tokens["pos"];
				auto actor = std::make_shared<Grunt>(b2Vec2(stoi(pos[0]), stoi(pos[1])), demo->getModel());
				demo->addActor(actor);
				demo->addView(std::make_shared<PatrolAI>(demo->getModel(), actor, b2Vec2(stoi(pos[0]), stoi(pos[1])), stoi(tokens["patrol_range"][0])));
			}
			else if (header == "barrel") {
				std::vector<std::string> pos = tokens["pos"];
				auto actor = std::make_shared<Barrel>(b2Vec2(stoi(pos[0]), stoi(pos[1])));
				demo->addActor(actor);
			}
			/* else if (header == "mast") {
				std::vector<std::string> pos = tokens["pos"];
				auto actor = std::make_shared<Mast>(b2Vec2(stoi(pos[0]), stoi(pos[1])));
				demo->addActor(actor);
			} */
		}
	}

	file.close();
	return demo;
}
