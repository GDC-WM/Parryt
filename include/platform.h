#ifndef PLATFORM_H
#define PLATFORM_H

#include "actor.h"

/**
 * Draw the screen for the player
 */
class Platform : public Actor {
	private:
		const double HEIGHT = 10; //why isn't this working?
		sf::RectangleShape shape;

	public:
		Platform(double x, double y, double width);

		sf::Shape &getShape(void) override;
};

#endif
