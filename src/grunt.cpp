#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "grunt.hpp"


Grunt::Grunt(b2Vec2 position) : Character(position) {
	this->allegiance = Allegiance::PIRATE;

	bodyDef.fixedRotation = true;
	this->bodyDef.type = b2_dynamicBody;

	// fix shape to body
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 2.4f;

	// set drawable
	texture.loadFromFile("../resources/pirate.png");
	this->sprite = sf::Sprite(texture, sf::IntRect(0,0,64,64));
	sprite.setScale(0.08,0.08); //hardcoding BAD

	//set old drawable
	this->drawable.setOrigin(this->WIDTH, this->HEIGHT);
	this->drawable.setFillColor(sf::Color::Red);
	this->drawable.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));
}


void Grunt::shoot() {
	return;
}


void Grunt::draw(std::shared_ptr<sf::RenderWindow> window) {
	// old drawable
	this->drawable.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	//window->draw(drawable);

	// For now we just draw the static image.
	this->sprite.setPosition(this->getBody()->GetPosition().x,
	                        -this->getBody()->GetPosition().y);

	window->draw(this->sprite);
}
