#ifndef PLAYER_VIEW_HPP
#define PLAYER_VIEW_HPP


#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.hpp"
#include "character.hpp"


/**
 * Draw the screen for the player
 */
class PlayerView : public View {
public:
	PlayerView(std::shared_ptr<LogicController> logic, std::shared_ptr<Character> character);

	void update(const float &dt);


private:
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<LogicController> logic;
	std::shared_ptr<Character> character;

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

	/**
	 * Draw the screen.
	 */
	void drawScreen(void);
};


#endif
