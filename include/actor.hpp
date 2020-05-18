#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <SFML/Graphics.hpp>


/**
 * Independent: Not affected by external forces
 * Grounded: currently on a physical actor
 * Airborne: in the air (not on a physical actor)
 */
enum class ActorState { INDEPENDENT, GROUNDED, AIRBORNE };

enum class CardinalDirection { NORTH, SOUTH, EAST, WEST };


/*
 * Base class that all actors in the game inherit from
 */
class Actor {
	private:
		sf::RectangleShape shape;

	protected:
		/**
		 * x and y -- the coordinates of the top left pixel
		 * width and height -- the number of pixels on the sides
		 * speed -- magnitude of the speed of the actor
		 */
		double x, y, width, height, xSpeed, ySpeed;
		int orientation; // orientation of the actor
		ActorState state;

	public:
		Actor(const double &x, const double &y, const double &width, const double &height);

		virtual const bool isPhysical(void) const { return false; };

		const ActorState &getState(void) const { return (this->state); };

		void setX(double x) { this->x = x; };

		void setY(double y) { this->y = y; };

		const double &getX(void) const { return this->x; };

		const double &getY(void) const { return this->y; };

		const double getCenterX(void) const { return (this->x + this->width / 2); };

		const double getCenterY(void) const { return (this->y + this->height / 2); };

		void setPos(double x, double y) { this->x = x; this->y = y; };

		void setWidth(double w) { this->width = w; };

		void setHeight(double h) { this->height = h; };

		const double &getWidth(void) const { return this->width; };

		const double &getHeight(void) const { return this->height; };

		void setDimensions(double width, double height) { this->width = width; this->height = height; };

		const double &getXSpeed(void) const { return this->xSpeed; };

		const double &getYSpeed(void) const { return this->ySpeed; };

		const double getSpeed(void) const;

		void hardStop(void) { this->xSpeed = this->ySpeed = 0; };

		const double getDirection(void) const;

		/**
		 * Sets the orientation of the actor.
		 *
		 * d -- direction to face
		 */
		void setOrientation(const int &d) { this->orientation = d; };

		/**
		 * Sets the orientation of the actor.
		 *
		 * x -- x coordinate to face
		 * y -- y coordinate to face
		 */
		void setOrientation(const int &x, const int &y);

		/**
		 * Sets the orientation of the actor.
		 *
		 * a -- the actor to face towards
		 */
		void setOrientation(const Actor &a);

		/**
		 * Returns the orientation of the actor.
		 */
		const int &getOrientation() const { return this->orientation; };

		/**
		 * Calculates if square Actor a is touching this square actor. (the
		 * outer pixels are next to eachother, or the actors are overlapping).
		 *
		 * a -- the actor for comparison
		 */
		const bool collidesSquare(const Actor &a) const;

		/**
		 * Returns the square actor created by the overlap of another actor and
		 * the current actor.
		 *
		 * a -- the actor it is overlapping withactor
		 */
		const Actor &getSquareOverlap(const Actor &a) const;

		/**
		 * Calculates if circular Actor a is touching this circular actor. (the
		 * outer pixels are next to eachother, or the actors are overlapping).
		 *
		 * a -- the actor for comparison
		 */
		const bool collidesCircle(const Actor &a) const;

		/**
		 * Calculates if Actor a is within a range of this actor.
		 *
		 * a -- the actor for comparison
		 * range -- the distance away from the actor to check within
		 */
		const bool collidesCircle(const Actor &a, int range) const;

		const bool liesInsideSquare(const Actor &a) const;

		virtual void update(const float &dt);

		void setShapePos(const double &x, const double &y) { this->shape.setPosition(x, y);std::cout << this->shape.getPosition().x; };

		/**
		 * Return shape to draw.
		 */
		virtual const sf::Shape &getShape(void) const { return this->shape; };
};

#endif
