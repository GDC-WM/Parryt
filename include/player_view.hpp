#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H


#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.hpp"
#include "character.hpp"


/**
 * Draw the screen for the player
 */
class PlayerView : public View {
	private:
		std::shared_ptr<sf::RenderWindow> window;

		std::shared_ptr<MasterLogic> logic;

		std::shared_ptr<Character> character;

		void pollInput(void);

		void listen(void);

	public:
		PlayerView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Character> character);

		void update(const float &dt);
};


#endif
