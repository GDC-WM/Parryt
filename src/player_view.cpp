#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.hpp"
#include "player_view.hpp"
#include "character.hpp"


PlayerView::PlayerView(std::shared_ptr<LogicController> logic, std::shared_ptr<Character> character) : View(logic) {
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
	
	/* Fix the left and right problem causing weird movements... */
	if (left && right) this->character->stop();
}


void PlayerView::listen(void) {
	sf::Event event;
	//left click to see the coordinates
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::Vector2i coords = sf::Mouse::getPosition(*window);
			sf::Vector2f worldPos = this->window->mapPixelToCoords(coords);
			std::cout<<" \ny: " << worldPos.y<< " \nx: " << worldPos.x;
		}
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window->close();
				this->logic->terminate();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Space:
					case sf::Keyboard::W:
						this->character->jump();
						break;

					default:; // ignore other keys
				}
				break;
			default:; // ignore other events
		}
	}
}


void PlayerView::viewFollow(const Actor &actor) {
	sf::View view = this->window->getView();

	b2Vec2 actorPosition = actor.getBody()->GetPosition();
	view.setCenter(actorPosition.x, -actorPosition.y);

	this->window->setView(view);
}


void PlayerView::drawScreen(void) {
	// clear screen
	this->window->clear(sf::Color::Black);

	// temporary background
	sf::Texture texture;
	texture.loadFromFile("../resources/demo-background.png");
	sf::Sprite background(texture, sf::IntRect(0, 0, 100000, 512));
	sf::Vector2u size = texture.getSize();
	texture.setRepeated(true);
	background.setTexture(texture);
	background.setOrigin(size.x / 2 + 1500, size.y / 2 + 150);
	background.setScale(0.125, 0.125);
	this->window->draw(background);

	// temporary shipbottom
	sf::Texture shipbot;
	shipbot.loadFromFile("../resources/shipbottom.png");
	sf::Sprite ship(shipbot, sf::IntRect(0, 0, 100000, 512));
	sf::Vector2u sizu = shipbot.getSize();
	shipbot.setRepeated(true);
	ship.setTexture(shipbot);
	ship.setOrigin(sizu.x / 2 + 1500, sizu.y / 2);
	ship.setPosition(sf::Vector2f(0, 45.2));
	ship.setScale(0.125, 0.125);
	this->window->draw(ship);

	// temporary mast drawing
	texture.loadFromFile("../resources/mast.png");
	sf::Sprite mast(texture, sf::IntRect(0, 0, 128, 512));
	mast.setPosition(sf::Vector2f(12, -92));
	mast.setScale(.2, .2);
	this->window->draw(mast);

	// temporary barrel drawing
	texture.loadFromFile("../resources/barrel.png");
	sf::Sprite barrel(texture, sf::IntRect(0,0,64,64));
	barrel.setPosition(sf::Vector2f(12, 4));
	barrel.setScale(.1,.1);
	this->window->draw(barrel);

	// draw actors
	for (auto actor : this->logic->getCurrentRoom()->getActorList()) actor->draw(this->window);

	// follow character
	this->viewFollow(*this->character);

	// display screen
	this->window->display();
}


void PlayerView::update(const float &dt) {
	this->pollInput();
	this->listen();
	this->drawScreen();
}
