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
    static constexpr float WIDTH = 0.5;
	static constexpr float HEIGHT = 1.9;

    Grunt(b2Vec2 position);

    /**
     * @return the damage delt by the enemy
     */
    int getDMG(void){return this-> dmg;};

    /**
     * fires a bullet out of the grunt's weapon
     */
    void shoot(void);


	void draw(std::shared_ptr<sf::RenderWindow> window) override;

protected:
	int bulletCounter = 0;
    int chamberSize = 5;
    int refractoryCounter =0;
    int refractoryTime= 30;
    int reloadTime = 100;
    int reloadCounter =0;
	int dmg = 10;

	sf::RectangleShape drawable;
	sf::Texture texture;
	b2PolygonShape shape;
	sf::Sprite sprite;

};


#endif
