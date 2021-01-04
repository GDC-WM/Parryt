#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "platform.hpp"


Platform::Platform(b2Vec2 position, float width) : Actor(position) {
	// set shape
	b2Vec2 vert1 = position;
	b2Vec2 vert2 = position;
	vert1.x += width;
	vert2.x -= width;

	b2Vec2 vert0 = vert1;
	b2Vec2 vert3 = vert2;

	vert0.y -= 0.1;
	vert3.y -= 0.1;

	this->shape.SetOneSided(vert0, vert1, vert2, vert3);

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.1f;

	// set drawable
	this->drawable.setOrigin(width, this->HEIGHT);
	sf::Color color(255, 0, 0);
	this->drawable.setFillColor(color);
	this->drawable.setSize(sf::Vector2f(width * 2, this->HEIGHT * 2));
}


void Platform::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->drawable.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	window->draw(drawable);
}
