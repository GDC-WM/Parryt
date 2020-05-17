#ifndef PARI_H
#define PARI_H

#include <SFML/Graphics.hpp>

#include "actor.h"
#include "character.h"

/**
 * The main character
 */
class Pari : public Character {
	private:
		sf::RectangleShape shape;

	public:
		Pari(double x, double y);

		sf::Shape &getShape(void) override;
};

#endif
