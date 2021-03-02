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
    

    void update(const float &dt);


    /**
     * returns the damage the grunt deals
     * @return the damage delt by the grunt
     */
    int getDMG(void){return this-> dmg;};


    /**
     * gives the grunt a post to patrol
     * @param post the coordinates of the center of their post
     */
    void setPost(b2Vec2 post){ this->post = post;};

    /**
     * returns the grunt's post
     * @return post
     */
    b2Vec2 getPost(){return this->post;};


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
    
    b2Vec2 post; //default post, should be changed whenever a grunt is added
                                 // unless only 1 grunt per level

	sf::RectangleShape drawable;
	sf::Texture texture;
	b2PolygonShape shape;
	sf::Sprite sprite;

};


#endif
