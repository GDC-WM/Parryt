#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.hpp"
#include "player_view.hpp"
#include "character.hpp"
#include "pari.hpp"


UserView::UserView(std::shared_ptr<GameController> logic, std::shared_ptr<Pari> character) : View(logic) {
	this->logic = logic; // TODO: this happens in view as well, but segfault if not set here
	this->character = character;

	// set window
	this->window = std::make_shared<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "Parryt", sf::Style::Titlebar | sf::Style::Close);

	// set view to center on the character
	sf::View view = this->window->getView();
	view.setSize(sf::Vector2f(64, 36));
	view.setCenter(this->convertVec(this->character->getBody()->GetPosition()));
	this->window->setView(view);

}


void UserView::pressEvent(sf::Event::KeyEvent key) {
	switch (key.code) {
		case sf::Keyboard::Space:
		case sf::Keyboard::W:
			this->character->jump();
			break;
		case sf::Keyboard::A:
			this->character->setMovement(Dir::left);
			break;
		case sf::Keyboard::D:
			this->character->setMovement(Dir::right);
			break;
		default:; // ignore other keys
	}
}


void UserView::pressEvent(sf::Event::MouseButtonEvent button) {
	b2Vec2 mousePos = this->convertVec(this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))
	                - this->character->getBody()->GetPosition();
	switch (button.button) {
		case sf::Mouse::Left: {
			// helpful for debugging: left click to see the coordinates
			std::cout << " \nx: " << mousePos.x << " \ny: " << mousePos.y << std::endl;
			break;
		}
		case sf::Mouse::Right: {
			this->character->parry(atan2(mousePos.y, mousePos.x));
			break;
		}
		default:; // ignore other buttons
	}
}


void UserView::releaseEvent(sf::Event::KeyEvent key) {
	switch (key.code) {
		case sf::Keyboard::A:
			if (this->character->getMovement() == Dir::left) this->character->setMovement(Dir::none);
			break;
		case sf::Keyboard::D:
			if (this->character->getMovement() == Dir::right) this->character->setMovement(Dir::none);
			break;
		default:; // ignore other keys
	}
}


void UserView::releaseEvent(sf::Event::MouseButtonEvent button) {
	switch (button.button) {
		case sf::Mouse::Left:
			break;
		default:; // ignore other buttons
	}
}


void UserView::listen(void) {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window->close();
				this->logic->terminate();
				break;
			case sf::Event::KeyPressed:
				this->pressEvent(event.key);
				break;
			case sf::Event::KeyReleased:
				this->releaseEvent(event.key);
				break;
			case sf::Event::MouseButtonPressed:
				this->pressEvent(event.mouseButton);
				break;
			case sf::Event::MouseButtonReleased:
				this->releaseEvent(event.mouseButton);
				break;
			default:; // ignore other events
		}
	}
}


void UserView::viewFollow(const Actor &actor) {
	sf::View view = this->window->getView();

	b2Vec2 actorPosition = actor.getBody()->GetPosition();
	view.setCenter(actorPosition.x, -actorPosition.y);

	this->window->setView(view);
}


void UserView::drawScreen(void) {
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

	// temporary add red vector indicating direction to redirect projectiles
	float point1[] = { window->getView().getCenter().x, window->getView().getCenter().y };
	float point2[] = { window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x, window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y };
	float vectorBetween[] = { point2[0] - point1[0], point2[1] - point1[1] };
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(point1[0], point1[1]), sf::Color::Red),
		sf::Vertex(sf::Vector2f(point2[0], point2[1]), sf::Color::Red)
	};
	this->window->draw(line, 2, sf::Lines);

	// draw actors
	for (auto actor : this->logic->getCurrentRoom()->getActorList()) actor->draw(this->window);

	// follow character
	this->viewFollow(*this->character);

	// display screen
	this->window->display();
}


void UserView::update(const float &dt) {
	this->listen();
	this->drawScreen();
}
