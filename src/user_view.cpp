#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <chrono>
#include <iostream>

#include "user_view.hpp"
#include "game_controller.hpp"
#include "game_state.hpp"
#include "game_state_factory.hpp"
#include "model.hpp"
#include "pari.hpp"
#include "dialog.hpp"


UserView::UserView(std::shared_ptr<GameController> game) {
	this->game = game;
	this->game->setGameState(this->gameStateFactory.build("../levels/demo.ini"));

	// add Pari to game
	this->character = std::make_shared<Pari>(b2Vec2(-30,-8)); // TODO: read Pari position from level file
	this->game->getGameState()->addActor(this->character);

	// set window
	this->window = std::make_shared<sf::RenderWindow>
			(sf::VideoMode(1280, 720, 32), "Parryt", sf::Style::Titlebar | sf::Style::Close);

	// set view to center on the character
	sf::View view = this->window->getView();
	view.setSize(sf::Vector2f(64, 36));
	view.setCenter(glob::convertVec(this->character->getBody()->GetPosition()));
	this->window->setView(view);

	/* Calling and playing music for the stage: */
	this->musicTrack.openFromFile("../resources/MainTheme.wav");
	this->musicTrack.play();
	this->musicTrack.setLoop(true);
}


void UserView::pressEvent(sf::Event::KeyEvent key) {
	switch (key.code) {
		case sf::Keyboard::Space:
		case sf::Keyboard::W:
			this->character->jump();
			break;
		case sf::Keyboard::A:
			this->character->setMovement(glob::Dir::left);
			break;
		case sf::Keyboard::D:
			this->character->setMovement(glob::Dir::right);
			break;
		case sf::Keyboard::Escape:
		case sf::Keyboard::P:
			this->game->togglePause();
			break;
		case sf::Keyboard::Enter:
			if (this->game->isInDialogMode())
				gruntDialog.Advance();
			break;
		default:; // ignore other keys
	}
}


void UserView::pressEvent(sf::Event::MouseButtonEvent button) {
	b2Vec2 mousePos = glob::convertVec(this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))
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
			if (this->character->getMovement() == glob::Dir::left) this->character->setMovement(glob::Dir::none);
			break;
		case sf::Keyboard::D:
			if (this->character->getMovement() == glob::Dir::right) this->character->setMovement(glob::Dir::none);
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
				this->terminate();
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

	// temporary add red vector indicating direction to redirect projectiles
	float point1[] = { window->getView().getCenter().x, window->getView().getCenter().y };
	float point2[] = { window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x, 
			   window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y };
	float vectorBetween[] = { point2[0] - point1[0], point2[1] - point1[1] };
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(point1[0], point1[1]), sf::Color::Red),
		sf::Vertex(sf::Vector2f(point2[0], point2[1]), sf::Color::Red)
	};
	this->window->draw(line, 2, sf::Lines);

	if(this->character->getBody()->GetPosition().x >= 10 ) {
		gruntDialog.LoadDialogText("../resources/arial.ttf", "../resources/Test.txt");
		gruntDialog.SetDialogTextPosition(10,0);
		gruntDialog.SetDialogTextScale_Size(.07,.07,30);
		this->game->toggleDialog(true);
		gruntDialog.DrawDialog(this->window);
	}

	// draw actors
	for (auto actor : this->game->getGameState()->getModel()->getActorList()) 
		actor->draw(this->window);

	// follow character
	this->viewFollow(*this->character);

	// display screen
	this->window->display();
}


void UserView::update(void) {
	this->listen();
	this->lastUpdate = std::chrono::steady_clock::now();
}
