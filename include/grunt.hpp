#ifndef GRUNT_HPP
#define GRUNT_HPP


#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "character.hpp"


class SpriteSheet;
class Model;


/*
*  The basic grunt enemy class
*  TODO: create an actual weapons class to replace some of these methods.
*/
class Grunt : public Character {
public:
	static constexpr float WIDTH = 0.5;
	static constexpr float HEIGHT = 1.9; // currently inaccurate height

	Grunt(b2Vec2 position, std::shared_ptr<Model> model);

	void update(const float &dt) override;

	/**
	 * returns the damage the grunt deals
	 * @return the damage delt by the grunt
	 */
	int getDMG(void) { return this->dmg; };

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


private:
	std::shared_ptr<Model> model;
	int bulletCounter = 5;
	int chamberSize = 5;
	int fireRateCounter = 0;
	int fireRate = 30;
	int reloadTime = 100;
	int reloadCounter = 0;
	int dmg = 10;
	int gunAngle = 90;
	b2Vec2 shootDir;

	sf::RectangleShape drawable;
	sf::Texture texture;
	b2PolygonShape shape;
	sf::Sprite sprite;
};


#endif
