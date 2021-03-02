#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "grunt.hpp"


Grunt::Grunt(b2Vec2 position) : Character(position) {
	this->allegiance = Allegiance::PIRATE;
	this->setTargetable(true);
	this->post = position;

	this->acceleration = 10;
	this->deceleration = 250;
	this->jumpImpulse = 200;
	this->maxSpeed = 15;
	this->maxHealth = 100;
	this->maxJumps = 1;

	bodyDef.fixedRotation = true;
	this->bodyDef.type = b2_dynamicBody;

	// fix shape to body
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 2.0f;
	this->fixtureDef.friction = 1.0f;

	// set drawable
	texture.loadFromFile("../resources/pirate.png");
	this->sprite = sf::Sprite(texture, sf::IntRect(0,0,64,64));
	sprite.setScale(0.08,0.08); //hardcoding BAD
	this->sprite.setOrigin(32 * .08, 32 * .08);

	//set old drawable
	this->drawable.setOrigin(this->WIDTH, this->HEIGHT);
	this->drawable.setFillColor(sf::Color::Red);
	this->drawable.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));
}


void Grunt::shoot() {
	//check if grunt reloading
	//should we make it that he can shout x times in a row and then pauses to reload (more realistic)
	if(this->reloadTime >0){
		return;
	}
	if(this->bulletCounter<=0){
		this->reloadCounter=reloadTime;
		return;
	}
	if(this->refractoryCounter>0){
		return;
	}
	
	
	//create a bullet here and propel it foreward
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

void Grunt::update(const float &dt){

}
