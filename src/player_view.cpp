#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.hpp"
#include "player_view.hpp"
#include "character.hpp"


PlayerView::PlayerView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Character> character) : View(logic) {
	this->logic = logic; // TODO: this happens in view as well, but segfault if not set here
	this->character = character;

	// set window
	this->window = std::make_shared<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "Parryt", sf::Style::Titlebar | sf::Style::Close);

	// set view to center on the character
	sf::View view = this->window->getView();
	view.setSize(sf::Vector2f(64, 36));
	view.setCenter(sf::Vector2f(this->character->getBody()->GetPosition().x,
                               -this->character->getBody()->GetPosition().y));
	this->window->setView(view);
}


// TODO: tie this method to the physics loop
void PlayerView::pollInput(void) {
	// mouse
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) ;

	// keyboard
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) /*jump down from platform*/;
	bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	if (left) this->character->goLeft();
	if (right) this->character->goRight();
	if (!(left || right)) this->character->stop();
}


void PlayerView::listen(void) {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window->close();
				this->logic->terminate();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Space:
						this->character->jump();
						break;
					default:; // ignore other keys
				}
				break;
			default:; // ignore other events
		}
	}
}


void PlayerView::drawScreen(void) {
	// clear screen
	window->clear(sf::Color::Black);

	// background test
	sf::Texture texture;
	texture.loadFromFile("../resources/demo_background.png");
	sf::Sprite sprite;
	sf::Vector2u size = texture.getSize();
	texture.setRepeated(true);
	sprite.setTexture(texture);
	sprite.setOrigin(size.x / 2 + 1500, size.y / 2 + 150);
	sprite.setScale(0.05, 0.05);
	sprite.setTextureRect(sf::IntRect(0, 0, 100000, 500));
	this->window->draw(sprite);

	// barrel
	sf::Texture barrel;
	texture.loadFromFile("../resources/barrel.png");
	sf::Sprite barr(texture, sf::IntRect(0,0,64,64));
	barr.setPosition(sf::Vector2f(12, -4));
	barr.setScale(.1,.1);
	this->window->draw(barr);

	//hung mast
	sf::Texture mast;
	texture.loadFromFile("../resources/mast.png");
	sf::Sprite mass(texture, sf::IntRect(0,0,64,64));
	barr.setPosition(sf::Vector2f(12, -4));
	barr.setScale(.1,2);
	this->window->draw(mass);


	// draw actors
	for (auto actor : this->logic->getCurrentRoom()->getActorList()) actor->draw(window);

	// screen follow character
	sf::Vector2f characterPosition = sf::Vector2f(this->character->getBody()->GetPosition().x,
	                                             -this->character->getBody()->GetPosition().y);
	sf::View view = this->window->getView();
	sf::Vector2f newCenter(view.getCenter().x, characterPosition.y);
	if (characterPosition.x + 10 < view.getCenter().x) newCenter.x -= 0.15;
	else if (characterPosition.x - 10 > view.getCenter().x) newCenter.x += 0.15;

	view.setCenter(newCenter);
	this->window->setView(view);

	// display screen
	window->display();
}


void PlayerView::update(const float &dt) {
	this->pollInput();
	this->listen();
	this->drawScreen();
}
