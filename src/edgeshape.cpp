#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "edgeshape.hpp"


Edgeshape::Edgeshape(b2Vec2 vec1, b2Vec2 vec2) : Actor(position) {

}


void EdgeShape::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->drawable.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	window->draw(drawable);
}
