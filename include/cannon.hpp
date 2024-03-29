#ifndef CANNON_HPP
#define CANNON_HPP

#include <box2d/box2d.h>

#include "actor.hpp"
#include "sprite_sheet.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Model;

/**
 * Draw the screen for the player
 */
class Cannon : public Actor
{
public:
	static constexpr float WIDTH = 1;
	static constexpr float HEIGHT = 1.2;
	static constexpr int LOAD_TIME = 90; // milliseconds
	sf::Vector2f barrelDimensions{2, 0.5};
	static constexpr float ROTATION_SPEED = M_PI / 6; // per second

	Cannon(b2Vec2 position, std::shared_ptr<Model> model);

	/*
	 * Returns angle of the barrel
	 */
	float getOrientation(void) { return this->barrelAngle; };

	/*
	 * Fire the cannon
	 */
	void shoot(void);

	/*
	 * Rotate the cannon clockwise
	 */
	void rotClockwise(void) { this->rotationVelocity = -this->ROTATION_SPEED / 60; };

	/*
	 * Rotate the cannon counterclockwise
	 */
	void rotCounterclockwise(void) { this->rotationVelocity = this->ROTATION_SPEED / 60; };

	/*
	 * Stop rotation
	 */
	void rotateStop(void) { this->rotationVelocity = 0; };

	void update(void) override;

	virtual void draw(std::shared_ptr<sf::RenderWindow> window) override;

private:
	std::shared_ptr<Model> model;
	b2PolygonShape shape;
	float rotationVelocity = 0;
	float barrelAngle = M_PI / 2;
	float minAngle = 9 * M_PI / 16;
	float maxAngle = M_PI;

	sf::Texture carriageTexture;
	sf::Sprite carriageSprite;
	std::unique_ptr<SpriteSheet> spriteSheet;
	Loop shootLoop{0, 18, 40};
	Loop idleLoop{0, 1, 1};

	int loadingCounter = 0;
};

#endif
