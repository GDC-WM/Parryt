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

	// set view to center on the character
	sf::View view = this->window->getView();
	view.setCenter(this->character->getDrawableCenter());
	this->window->setView(view);
}


// TODO: tie this method to the physics loop
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

	// draw the screen
	for (auto actor : this->logic->getCurrentRoom().getActorList()) this->window->draw(actor->getDrawable());
}
