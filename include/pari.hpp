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
		b2PolygonShape shape;

	public:
		Pari(double x, double y);
};


#endif
