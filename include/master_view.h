#ifndef MASTER_VIEW_H
#define MASTER_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "master_logic.h"
#include "actor.h"

#include "view.h"
#include "room.h"
#include "exit.h"

/*
 * Manages all of the different views and game states
 */
class MasterView {
	private:
		std::shared_ptr<sf::RenderWindow> window;
		std::shared_ptr<MasterLogic> logic;
		std::shared_ptr<PlayerView> player;

	public:
		MasterView(std::shared_ptr<sf::RenderWindow> window);

		// change how this works? not necessary use shared from this
		void init(std::shared_ptr<MasterLogic> logic);

		void reset();

		/**
		 * Create a view for the new enemy from logic and add the view to the enemyview list
		 */
		void update(float dt);
};

#endif
