#ifndef MAST_HPP
#define MAST_HPP


#include <box2d/box2d.h>

#include "actor.hpp"
#include "platform.hpp"


class Mast : public Actor {
public:
	static constexpr float height = 0.1;

	Mast(b2Vec2 position, int height);

	virtual void draw(std::shared_ptr<sf::RenderWindow> window);

private:
	b2PolygonShape shape;
	b2Vec2 coords;
	sf::RectangleShape drawable;
	sf::Texture texture;
	sf::Sprite sprite;
};


#endif
