#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <iostream>

#include "view.hpp"
#include "player_view.hpp"
#include "character.hpp"


PlayerView::PlayerView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Character> character,
                       std::shared_ptr<sf::RenderWindow> window)
		: View(logic) {
	this->logic = logic;
	this->character = character;
	this->window = window;
}


void PlayerView::pollInput() {
	// mouse
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) ;

	// keyboard
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->character->goLeft();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) /*jump down from platform*/;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->character->goRight();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) this->character->jump();
}


void PlayerView::update(const float &dt) {
	this->pollInput();

	// draw actors
	for (auto actor : this->logic->getCurrentRoom().getActorList()) { this->window->draw(actor->getDrawable()); }

	// screen follow character
	sf::View curView = this->window->getView();
	if (this->character->getDrawable().getPosition().x + 50 < curView.getCenter().x) {
		curView.setCenter(sf::Vector2f(curView.getCenter().x - 0.3, this->character->getDrawable().getPosition().y));
	}
	else if (this->character->getDrawable().getPosition().x - 50 > this->window->getView().getCenter().x) {
		curView.setCenter(sf::Vector2f(curView.getCenter().x + 0.3, this->character->getDrawable().getPosition().y));
	}
	else curView.setCenter(sf::Vector2f(curView.getCenter().x, this->character->getDrawable().getPosition().y));
	this->window->setView(curView);
}
