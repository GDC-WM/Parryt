#ifndef GRUNT_HPP
#define GRUNT_HPP


#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "sprite_sheet.hpp"


/*
*  The basic grunt enemy class
*  TODO: create an actual weapons class to replace some of these methods.
*/
class Grunt : public Character {
public:
	static constexpr float WIDTH = 0.5;
	static constexpr float HEIGHT = 1.9; // currently inaccurate height

	Grunt(b2Vec2 position);

	void update(const float &dt);

	/**
	 * returns the damage the grunt deals
	 * @return the damage delt by the grunt
	 */
	int getDMG(void) { return this->dmg; };

	/**
	 * gives the grunt a post to patrol
	 * @param post the coordinates of the center of their post
	 */
	void setPost(b2Vec2 post) { this->post = post; };

	/**
	 * returns the grunt's post
	 * @return post
	 */
	b2Vec2 getPost() { return this->post; };

	/**
	 * fires a bullet out of the grunt's weapon
	 */
	void shoot(void);

	/**
	 * @return the current angle of the gun
	 */
	float getGunAngle() { return this->gunAngle; };

	/**
	 * sets the gun angle
	 * @param angle the new gun angle
	 */
	void setGunAngle(float angle) { this->gunAngle = angle; };

	void setShootDir(b2Vec2 direction) { this->shootDir = direction; };

	void draw(std::shared_ptr<sf::RenderWindow> window) override;


protected:
	int bulletCounter = 5;
	int chamberSize = 5;
	int fireRateCounter = 0;
	int fireRate = 30;
	int reloadTime = 100;
	int reloadCounter = 0;
	int dmg = 10;
	int gunAngle = 90;
	b2Vec2 shootDir;
	b2Vec2 post; // TODO: move all post code to an ai class.

	sf::RectangleShape drawable;
	sf::Texture texture;
	b2PolygonShape shape;
	sf::Sprite sprite;
};


#endif
