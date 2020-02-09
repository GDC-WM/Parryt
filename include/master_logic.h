#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.h"
#include "room.h"

class MasterView;

/*
* Main logic class that controls everything.
*/
class MasterLogic {
	private:
		std::shared_ptr<MasterView> view;
		std::list<std::shared_ptr<Room>> roomList;
		std::list<std::shared_ptr<Room>>::iterator currentRoom;
		std::list<std::shared_ptr<Actor>> actorList;

	public:
		bool paused = true;

		/*
		 * Main method
		 */
		MasterLogic(void) { };

		/*
		 *
		 */
		void init(std::shared_ptr<MasterView> mv);


		/*
		 * Start main menu
		 */
		void startMenu(void);

		/*
		 * Start a demo of gameplay
		 */
		void startDemo(void);

		/*
		 *
		 */
		std::shared_ptr<Room> getCurrentRoom(void) { return *(this->currentRoom); };

		/*
		 *
		 */
		void checkCollisions(void);

		/*
		 * Resets master logic
		 */
		void reset(void);

		/*
		 *
		 */
		void update(float dt);
};

#endif