#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <iostream>

#include "master_logic.h"
#include "master_view.h"

int main(int argc, char** argv) {
	// game window
	std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1200,900,32), "Project Parry", sf::Style::Titlebar | sf::Style::Close);

	// game clock
	sf::Clock clock;

	// delta time
	float dt;

	std::shared_ptr<MasterLogic> logic = std::make_shared<MasterLogic>();
	std::shared_ptr<MasterView> view = std::make_shared<MasterView>(logic, window);
	logic->init(view);
	logic->startDemo();

	// game loop
	while (window->isOpen()) {
		dt = clock.getElapsedTime().asSeconds();
		clock.restart();

		window->clear(sf::Color::Black);

		logic->update(dt);
		view->update(dt);

		window->display();

		//check for window closed event
		sf::Event Event;
		while (window->pollEvent(Event))
			if (Event.type == sf::Event::Closed) window->close();
	}

	// Done.
	return 0;
}
