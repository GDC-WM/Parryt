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
		static constexpr float WIDTH = 0.8;
		static constexpr float HEIGHT = 0.5;
		sf::Vector2f barrelDimensions{2, 0.3};
		float barrelAngle = M_PI / 2;
		static constexpr float ROTATION_SPEED = M_PI / 4; // per second

		Cannon(b2Vec2 position);

		/*
		 * returns where the cannon is rotateed
		 */
		float getOrientation(void);

		/*
		 * Fire the cannon
		 */
		void shoot(void);

		/*
		 * Rotate the cannon clockwise
		 */
		void rotateClockwise(void) { this->rotationVelocity = this->ROTATION_SPEED; };

		/*
		 * Rotate the cannon counterclockwise
		 */
		void rotateCounterclockwise(void) { this->rotationVelocity = -this->ROTATION_SPEED; };

		/*
		 * Stop rotation
		 */
		void rotateStop(void) { this->rotationVelocity = 0; };

		void update(const float &dt) override;

		virtual void draw(std::shared_ptr<sf::RenderWindow> window);


	private:
		b2PolygonShape shape;
		float rotationVelocity = 0;
		sf::RectangleShape carriage;
		sf::RectangleShape barrel;
};


#endif
