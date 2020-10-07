#ifndef MASTER_VIEW_H
#define MASTER_VIEW_H


#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "master_logic.hpp"
#include "view.hpp"
#include "player_view.hpp"
#include "actor.hpp"
#include "pari.hpp"


/**
 * Manages all of the different views and game states
 */
class MasterView {
	private:
		std::shared_ptr<sf::RenderWindow> window;
		std::shared_ptr<MasterLogic> logic;
		std::list<std::shared_ptr<View>> viewList;

	public:
		MasterView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<sf::RenderWindow> window);

		void reset();

		/**
		 * Polymorphic way to add a view
		 */
		void addView(std::shared_ptr<Pari> p) { this->viewList.push_back(std::make_shared<PlayerView>(this->logic, p, this->window)); };

		/**
		 * Create a view for the new enemy from logic and add the view to the enemyview list
		 */
		void update(float dt);
};


#endif
