#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.hpp"
#include "room.hpp"

class MasterView;

/**
 * Main logic class that controls everything.
 */
class MasterLogic {
	private:
		std::shared_ptr<MasterView> view;
		std::list<Room> roomList;
		std::list<Room>::iterator currentRoom;
		bool paused = false;

	public:
		/**
		 * Main method
		 */
		MasterLogic(void) { };

		/**
		 *
		 */
		void init(std::shared_ptr<MasterView> mv);


		/**
		 * Start main menu
		 */
		void startMenu(void);

		/**
		 * Start a demo of gameplay
		 */
		void startDemo(void);

		/**
		 *
		 */
		const Room &getCurrentRoom(void) const { return *(this->currentRoom); };

		/**
		 *
		 */
		void checkCollisions(void);

		/**
		 * Resets master logic
		 */
		void reset(void);

		/**
		 *
		 */
		void update(const float &dt);

		sf::Event event;
};

#endif
