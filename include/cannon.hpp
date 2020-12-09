#ifndef CANNON_HPP
#define CANNON_HPP


#include <cmath>
#include <box2d/box2d.h>

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Cannon : public Actor {
	public:
		static constexpr float WIDTH = 1;
		static constexpr float HEIGHT = 1.2;
		static constexpr int LOAD_TIME = 90; // milliseconds
		sf::Vector2f barrelDimensions{2, 0.5};
		float barrelAngle = M_PI / 4;
		static constexpr float ROTATION_SPEED = M_PI / 6; // per second

		Cannon(b2Vec2 position);

		/*
		 * returns angle of the barrel
		 */
		float getOrientation(void);

		/*
		 * Fire the cannon
		 */
		void shoot(void);

		/*
		 * Rotate the cannon clockwise
		 */
		void rotateClockwise(void) { this->rotationVelocity = -this->ROTATION_SPEED / 60; };

		/*
		 * Rotate the cannon counterclockwise
		 */
		void rotateCounterclockwise(void) { this->rotationVelocity = this->ROTATION_SPEED / 60; };

		/*
		 * Stop rotation
		 */
		void rotateStop(void) { this->rotationVelocity = 0; };

		void update(const float &dt) override;

		virtual void draw(std::shared_ptr<sf::RenderWindow> window) override;


	private:
		b2PolygonShape shape;
		float rotationVelocity = 0;
		sf::RectangleShape carriage;
		sf::RectangleShape barrel;

		sf::Texture carriageTexture;
		sf::Sprite carriageSprite;
		sf::Texture barrelTexture;
		sf::Sprite barrelSprite;

		int loadingCounter = 0;
};


#endif
