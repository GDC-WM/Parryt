#include "barrel.hpp"
    
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"

Barrel::Barrel(b2Vec2 position) : Actor(position) {

	// set shape
	this->barrelShape.SetAsBox(this->WIDTH,this->HEIGHT);
	this->priority = 8;

	// fix shape to body
	this->bodyDef.type = b2_dynamicBody;
	this->fixtureDef.shape = &this->barrelShape;
	this->fixtureDef.density = 3.0f;
	this->fixtureDef.friction = 0.7f;

	// load image
	barrelTexture.loadFromFile("../resources/barrel.png");
	this->barrelSprite = sf::Sprite(barrelTexture);

	// set scale and origin
	barrelSprite.setScale(glob::scale,glob::scale);
	this->barrelSprite.setOrigin(this->WIDTH * 14 + 7.5, this->HEIGHT * 14 + 15);

}

// barrel should collide with player
const bool Barrel::shouldCollide(const Actor &a) const {
	return true;
}

// Draw the player to the screen
void Barrel::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->barrelSprite.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	window->draw(this->barrelSprite);
}
