#ifndef GRUNT_HPP
#define GRUNT_HPP


#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"


/*
*  The basic grunt enemy class
*/
class Grunt : public Character {
	public:
		static constexpr float WIDTH = 0.5;

		static constexpr float HEIGHT = 1.9;

		Grunt(b2Vec2 position);

		void shoot();

		void draw(std::shared_ptr<sf::RenderWindow> window) override;

	protected:
		int reloadCounter = 0;

		sf::RectangleShape drawable;
		sf::Texture texture;
		b2PolygonShape shape;
		sf::Sprite sprite;

};


#endif
