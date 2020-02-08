#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.h"
#include "room.h"
#include "exit.h"

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

        std::shared_ptr<Exit> currentExit;

		float delta;

    public:
        bool paused = true;

        MasterLogic(void) { };

        void init(std::shared_ptr<MasterView> mv);

        void startMenu(void);

        void startTutorial(void);

        void startDemo(void);

        void update(float delta);

        std::shared_ptr<Room> getCurrentRoom(void) { return *(this->currentRoom); };

        void checkCollisions(void);

        int getNightCount(void) { return nightCount; };

        void setNightCount(int num) { this->nightCount = num; };

        // Resets all the lists in the game for when the player wins or loses
        void reset(void);
};

#endif
