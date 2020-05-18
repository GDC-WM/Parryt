#ifndef PARI_H
#define PARI_H

#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"


/**
 * The main character
 */
class Pari : public Character {
	private:
		sf::RectangleShape shape;

	public:
		Pari(double x, double y);

		const sf::Shape &getShape(void) const override;
};

#endif
