#ifndef USER_VIEW_HPP
#define USER_VIEW_HPP


#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <box2d/box2d.h>

#include "view.hpp"


class GameController;
class Actor;
class Pari;


/**
 * Draw the screen for the player
 */
class UserView : public View, public std::enable_shared_from_this<UserView> {
public:
	UserView(std::shared_ptr<GameController> game);

	void update(const float &dt);


private:
	std::shared_ptr<GameController> game;
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<Pari> character;
	sf::Music musicTrack;
	//std::shared_ptr<sf::Music> Track;

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
