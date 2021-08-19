#ifndef USER_VIEW_HPP
#define USER_VIEW_HPP


#include <chrono>
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <box2d/box2d.h>

#include "view.hpp"
#include "game_state_factory.hpp"
#include "dialog.hpp"

class GameController;
class Actor;
class Pari;
class DialogSystem;

/**
 * Draw the screen for the player
 */
class UserView : public View {
public:
	UserView(std::shared_ptr<GameController> game);

	const bool &isRunning(void) { return this->running; };

	void terminate(void) { this->running = false; };

	/**
	 * Draw the screen.
	 */
	void drawScreen(void);

	void update(void) override;


private:
	bool running = true;
	std::chrono::steady_clock::time_point lastUpdate;
	std::shared_ptr<GameController> game;
	std::shared_ptr<sf::RenderWindow> window;
	GameStateFactory gameStateFactory;
	std::shared_ptr<Pari> character;
	std::shared_ptr<DialogSystem> dialog;
	sf::Music musicTrack;

	/**
	 * Respond to key press
	 */
	void pressEvent(sf::Event::KeyEvent key);

	/**
	 * Respond to mouse press
	 */
	void pressEvent(sf::Event::MouseButtonEvent button);

	/**
	 * Respond to key release
	 */
	void releaseEvent(sf::Event::KeyEvent key);

	/**
	 * Respond to mouse release
	 */
	void releaseEvent(sf::Event::MouseButtonEvent button);

	/**
	 * Respond to events
	 */
	void listen(void);

	/**
	 * Center the view on an actor.
	 *
	 * @param actor to center on
	 */
	void viewFollow(const Actor &actor);
};


#endif
