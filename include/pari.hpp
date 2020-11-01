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
		static constexpr float WIDTH = 0.5;

		static constexpr float HEIGHT = 1.9;

		Pari(float x, float y);
};


#endif
