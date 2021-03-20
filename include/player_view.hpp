#ifndef PLAYER_VIEW_HPP
#define PLAYER_VIEW_HPP


#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.hpp"
#include "character.hpp"
#include "pari.hpp"
#include "music.hpp"


/**
 * Draw the screen for the player
 */
class PlayerView : public View {
public:
	PlayerView(std::shared_ptr<LogicController> logic, std::shared_ptr<Pari> character);

	void update(const float &dt);


private:
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<LogicController> logic;
	std::shared_ptr<Pari> character;
	std::shared_ptr<musicTrack> ShipTrack;


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

	b2Vec2 convertVec(sf::Vector2f sfmlVec) { return b2Vec2(sfmlVec.x, -sfmlVec.y); };

	sf::Vector2f convertVec(b2Vec2 b2dVec) { return sf::Vector2f(b2dVec.x, -b2dVec.y); };
};


#endif
