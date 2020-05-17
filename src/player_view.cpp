#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.hpp"
#include "player_view.hpp"
#include "character.hpp"

PlayerView::PlayerView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Character> character, std::shared_ptr<sf::RenderWindow> window)
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        /*jump down from platform*/;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->character->goRight();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) /* set initial height and don't update if in air*/ this->character->jump();

}

void PlayerView::update(const float &dt) {
	this->pollInput();

	for (auto actor : this->logic->getCurrentRoom().getActorList()) {
		actor->getShape().setPosition(actor->getX(), actor->getY());
		this->window->draw(actor->getShape());
	}
}
