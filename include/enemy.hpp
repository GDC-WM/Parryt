#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "sprite_sheet.hpp"


/*
* the parent class for enemies
*/
class Enemy : public Character{
public:
    Enemy(b2Vec2 position);

    /**
     * @return the enemy's range
     */
    int getRange(void){return this->range;};
        

    /**
     * @return the damage delt by the enemy
     */
    int getDMG(void){return this-> dmg;};


    /**
     * @param range the range of the enemy
     */
    void setRange(int range){this->range = range;};


    /**
     * @param damage the damage this enemy deals
     */
    void setDMG(int damage){this->dmg = dmg;};


    /**
     * @return True if the hit landed, false if not
     * @param a The actor to hit
     */
    bool attack(std::shared_ptr<Actor> a){};




protected:
    int dmg;
    //possibly a weapon
    //sprite sheet?
    int range;


};


#endif