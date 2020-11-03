#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <thread>
#include <chrono>

#include "master_logic.hpp"
#include "master_view.hpp"

int main(int argc, char** argv) {

	sf::Texture texture;
	texture.loadFromFile("resources/Parryt-2.png");
	sf::Sprite sprite(texture, sf::IntRect(0,0,800,800));

	std::shared_ptr<MasterLogic> logic = std::make_shared<MasterLogic>();
	std::shared_ptr<MasterView> view = std::make_shared<MasterView>(logic);
	logic->init(view);
	logic->startDemo();

	std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();

	// game loop
	while (!logic->isTerminated()) {
		auto dt = std::chrono::system_clock::now() - startTime;
		startTime = std::chrono::system_clock::now();

		logic->update(16);
		view->update(16);

		std::this_thread::sleep_for(std::chrono::milliseconds(16) - dt);

	}

	/*
	while (window->isOpen()) {
		dt = clock.getElapsedTime().asSeconds();
		clock.restart();

		window->clear(sf::Color::Black);
		logic->update(dt);
		view->update(dt);
		window->display();

		//check for window closed event
		sf::Event Event;
		while (window->pollEvent(Event)) {
			if (Event.type == sf::Event::Closed) window->close();
		}
	}
	*/

	//TODO: separate variable rate graphics loop

	return 0;
}

