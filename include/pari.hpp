#ifndef PARI_H
#define PARI_H


#include <box2d/box2d.h>
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
		static constexpr double HEIGHT = 2;

		static constexpr double WIDTH = 0.5;

		Pari(double x, double y);
};


#endif
