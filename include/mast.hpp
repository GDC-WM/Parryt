#ifndef MAST_HPP
#define MAST_HPP


#include <box2d/box2d.h>

#include "actor.hpp"
#include "platform.hpp"


class Mast : public Actor {
	public:
		static constexpr float WIDTH = 0.1;

		Mast(b2Vec2 position, float height);

		virtual void draw(std::shared_ptr<sf::RenderWindow> window);

	private:
		b2PolygonShape shape;
        sf::RectangleShape drawable;
		sf::Texture texture;
        sf::Sprite sprite;
        Platform platform;
	};


#endif