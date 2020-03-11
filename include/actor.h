#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics.hpp>

enum class ActorState { GROUNDED, AIRBORNE };

/*
* Base class that all actors in the game inherit from
*/
class Actor {
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
		Actor(double x, double y, double width, double height);

		void setX(double x) { this->x = x; };

		const double &getX(void) const { return this->x; };

		void setY(double y) { this->y = y; };

		const double &getY(void) const { return this->y; };

		const double getCenterX(void) const { return (this->x + this->width / 2); };

		const double getCenterY(void) const { return (this->y + this->height / 2); };

		void setPos(double x, double y) { this->x = x; this->y = y; };

		const double &getWidth(void) const { return this->width; };

		void setWidth(double w) { this->width = w; };

		const double &getHeight(void) const { return this->height; };

		void setHeight(double h) { this->height = h; };

		void setDimensions(double width, double height) { this->width = width; this->height = height; };

		const double &getXSpeed(void) const { return this->xSpeed; };

		const double &getYSpeed(void) const { return this->ySpeed; };

		const double &getSpeed(void); const

		void hardStop(void) { this->xSpeed = this->ySpeed = 0; };

		const ActorState &getState(void) const { return (this->state); };

		const double &getDirection(void); const

		/**
		 * Sets the orientation of the actor.
		 *
		 * d -- direction to face
		 */
		void setOrientation(int d) { this->orientation = d; };

		/**
		 * Sets the orientation of the actor.
		 *
		 * x -- x coordinate to face
		 * y -- y coordinate to face
		 */
		void setOrientation(int x, int y);

		/**
		 * Sets the orientation of the actor.
		 *
		 * a -- the actor to face towards
		 */
		void setOrientation(Actor &a);

		/**
		 * Returns the orientation of the actor.
		 */
		const int &getOrientation() { return this->orientation; };

		/**
		 * Calculates if square Actor a is touching this square actor.
		 * (the outer pixels are next to eachother, or the actors are overlapping).
		 *
		 * a -- the actor for comparison
		 */
		const bool collidesSquare(Actor &a);

		/**
		 * Calculates if circular Actor a is touching this circular actor.
		 * (the outer pixels are next to eachother, or the actors are overlapping).
		 *
		 * a -- the actor for comparison
		 */
		const bool collidesCircle(Actor &a);

		/**
		 * Calculates if Actor a is within a range of this actor.
		 *
		 * a -- the actor for comparison
		 * range -- the distance away from the actor to check within
		 */
		const bool collidesCircle(Actor &a, int range);

		const bool liesInsideSquare(Actor &a);

		virtual void update(const float &dt);

		/*
		 * Return shape to draw.
		 */
		virtual sf::Shape &getShape(void) const = 0;

};

#endif
