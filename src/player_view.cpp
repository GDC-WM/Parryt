#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <iostream>

#include "view.hpp"
#include "player_view.hpp"
#include "character.hpp"


PlayerView::PlayerView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Character> character)
		: View(logic) {
	this->logic = logic;
	this->character = character;

	// set window
	this->window = std::make_shared<sf::RenderWindow>
			(sf::VideoMode(1200, 900, 32), "Parryt", sf::Style::Titlebar | sf::Style::Close);

	// set view to center on the character
	sf::View view = this->window->getView();
	view.setCenter(this->character->getDrawableCenter());
	this->window->setView(view);
}


// TODO: tie this method to the physics loop
void PlayerView::pollInput(void) {
	// mouse
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) ;

	// keyboard
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->character->goLeft();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) /*jump down from platform*/;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->character->goRight();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) this->character->jump();
}

void PlayerView::listen(void) {
		sf::Event Event;
		while (window->pollEvent(Event)) {
			if (Event.type == sf::Event::Closed) {
				window->close();
				this->logic->terminate();
			}
		}
}


void PlayerView::update(const float &dt) {
	this->pollInput();
	this->listen();

	// clear screen
	window->clear(sf::Color::Black);

	// update drawables
	for (auto actor : this->logic->getCurrentRoom().getActorList()) actor->updateDrawable();

	// screen follow character
	sf::Vector2f characterPosition = this->character->getDrawableCenter();
	sf::View view = this->window->getView();
	sf::Vector2f newCenter(view.getCenter().x, characterPosition.y);

	if (characterPosition.x + 50 < view.getCenter().x) newCenter.x -= 0.3;
	else if (characterPosition.x - 50 > view.getCenter().x) newCenter.x += 0.3;

	view.setCenter(newCenter);
	this->window->setView(view);

	// draw actors
	for (auto actor : this->logic->getCurrentRoom().getActorList()) this->window->draw(actor->getDrawable());

	// display screen
	window->display();
}
