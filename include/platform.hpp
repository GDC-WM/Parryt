#ifndef PLATFORM_H
#define PLATFORM_H

#include "actor.hpp"

/**
 * Draw the screen for the player
 */
class Platform : public Actor {
	private:
		const double HEIGHT = 10; //why isn't this working?
		sf::RectangleShape shape;

	public:
		virtual const bool isPhysical(void) const override { return true; };

		Platform(double x, double y, double width);

		sf::Shape &getShape(void) override;
};

#endif
