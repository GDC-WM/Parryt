#ifndef GRUNT_HPP
#define GRUNT_HPP


#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "sprite_sheet.hpp"


/*
*  The basic grunt enemy class
*/
class Grunt : public Character {
public:
    Grunt(b2Vec2 position);

    /**
     * @return the enemy's range
     */
    int getRange(void){return this->range;};
        

    /**
     * @return the damage delt by the enemy
     */
    int getDMG(void){return this-> dmg;};

    /**
     * @param a The actor to hit
     */
    void shoot(std::shared_ptr<Actor> a){};


	void draw(std::shared_ptr<sf::RenderWindow> window) override;

protected:
	int reloadCounter = 0;
	int dmg = 10;
	int range = 10;

	sf::RectangleShape drawable;
	sf::Texture texture;
	b2PolygonShape shape;
	sf::Sprite sprite;

};


#endif
