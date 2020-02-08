#ifndef ROOM_H
#define ROOM_H

#include <list>
#include <memory>

#include "actor.h"
#include "character.h"
#include "fred.h"
#include "item.h"
#include "trap.h"
#include "bullet.h"
#include "bed.h"
#include "closet.h"
#include "portal.h"
#include "health_item.h"
#include "range_weapon.h"
#include "health_item.h"
#include "cheryl.h"

class Exit;
class Fred;
class Enemy;

// Handles state management between the two rooms and all of the different actor lists
class Room : public Actor, public std::enable_shared_from_this<Room> {
    private:
        // Actor lists
        std::list<std::shared_ptr<Actor>> actorList;
        std::list<std::shared_ptr<Exit>> exitList;
        std::shared_ptr<Fred> fred;
        std::shared_ptr<Cheryl> cheryl;
        std::list<std::shared_ptr<Enemy>> enemyList;
        std::list<std::shared_ptr<Item>> itemList;
        std::list<std::shared_ptr<Bullet>> bulletList;
        std::list<std::shared_ptr<Portal>> portalList;

        bool loser = false;
        
    public:
        Room(double x, double y, double width, double height);
        
        void setActorList(std::list<std::shared_ptr<Actor>> newActorList) { this->actorList = newActorList; };
        void setItemList(std::list<std::shared_ptr<Item>> newItemList) { this->itemList = newItemList; };

        /**
         * Add an actor to the actor lists for actors of its type.
         */
        void addActor(std::shared_ptr<Exit> exit);

        void addActor(std::shared_ptr<Fred> fred);

        void addActor(std::shared_ptr<Enemy> enemy);

        void addActor(std::shared_ptr<Item> item);

        void addActor(std::shared_ptr<Bullet> bullet);
    
        void addActor(std::shared_ptr<Bed> bed);
    
        void addActor(std::shared_ptr<Closet> closet);

        void addActor(std::shared_ptr<Portal> portal);

        void addActor(std::shared_ptr<Cheryl> cheryl);

        /**
         * Remove an actor from the actor lists for actors of its type.
         */
        void removeActor(std::shared_ptr<Exit> exit);

        void removeActor(std::shared_ptr<Fred> fred);

        void removeActor(std::shared_ptr<Enemy> enemy);

        void removeActor(std::shared_ptr<Item> item);

        void removeActor(std::shared_ptr<Bullet> bullet);
        
        void removeActor(std::shared_ptr<Portal> portal);
        
        std::list<std::shared_ptr<Item>> getItemList(void) { return this->itemList; };

        std::list<std::shared_ptr<Exit>> getExitList(void) { return this->exitList; };
        
        std::shared_ptr<Fred> getFred(void) { return this->fred; };

        std::shared_ptr<Cheryl> getCheryl(void) { return this->cheryl; };
        
        std::list<std::shared_ptr<Enemy>> getEnemyList(void) { return this->enemyList; };
        
        std::list<std::shared_ptr<Bullet>> getBulletList(void) { return this->bulletList; };

        std::list<std::shared_ptr<Portal>> getPortalList(void) { return this->portalList; };

        /**
         * Return the whole list of actors.
         */
        std::list<std::shared_ptr<Actor>> getActorList(void) { return this->actorList; };

        std::shared_ptr<Fred> getFred(ActorType t) { return this->fred; };

        void reset(void);
};

#endif
