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
	PlayerView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Character> character);

	void update(const float &dt);


private:
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<MasterLogic> logic;
	std::shared_ptr<Character> character;

	/**
	 * Poll input methods and react accordingly.
	 */
	void pollInput(void);

	/**
	 * Poll input events and react accordingly.
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
