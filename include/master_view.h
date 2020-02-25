#ifndef MASTER_VIEW_H
#define MASTER_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "master_logic.h"
#include "actor.h"
#include "pari.h"

#include "view.h"
#include "player_view.h"

/**
 * Manages all of the different views and game states
 */
class MasterView {
	private:
		std::shared_ptr<sf::RenderWindow> window;
		std::shared_ptr<MasterLogic> logic;
		std::list<std::unique_ptr<View>> viewList;

	public:
		MasterView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<sf::RenderWindow> window);

		void reset();

		void addView(std::shared_ptr<Pari> p) { this->viewList.push_back(std::make_unique<PlayerView>(this->logic, p, this->window)); };

		/**
		 * Create a view for the new enemy from logic and add the view to the enemyview list
		 */
		void update(float dt);
};

#endif
