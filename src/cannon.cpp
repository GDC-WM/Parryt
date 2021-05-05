#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <list>

#include "cannon.hpp"
#include "cannonball.hpp"
#include "model.hpp"


Cannon::Cannon(b2Vec2 position, std::shared_ptr<Model> model) : Actor(position) {
	this->model = model;
	this->allegiance = Allegiance::pirate;

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->bodyDef.enabled = false;
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// load barrel spritesheet
	this->spriteSheet = std::make_unique<SpriteSheet>("../resources/cannon-barrel-spritesheet.png", sf::Vector2i(64, 64));
	this->spriteSheet->setLoop(this->idleLoop);
	this->spriteSheet->getSprite().setOrigin(this->WIDTH * 14, this->HEIGHT * 14);

	// set carriage
	carriageTexture.loadFromFile("../resources/cannon-carriage.png");
	this->carriageSprite = sf::Sprite(carriageTexture, sf::IntRect(0,0,64,64));
	carriageSprite.setScale(0.08, 0.08);
	this->carriageSprite.setOrigin(this->WIDTH * 14, this->HEIGHT * 14 - 10);
}


void Cannon::shoot(void) {
	if (this->loadingCounter > 0) return;
	this->spriteSheet->setOneShot(this->shootLoop);
	this->loadingCounter = this->LOAD_TIME;
}


void Cannon::update(void) {
	// update barrel angle
	this->barrelAngle += this->rotationVelocity;
	if (this->barrelAngle < this->minAngle) this->barrelAngle = this->minAngle;
	if (this->barrelAngle > this->maxAngle) this->barrelAngle = this->maxAngle;

	// deal with shooting
	if (this->loadingCounter == 0) return;
	this->loadingCounter--;
	if (this->loadingCounter == this->LOAD_TIME - 40) {
		std::shared_ptr<Cannonball> cannonball = std::make_shared<Cannonball>(this->body->GetPosition(), 20);
		this->model->addActor(cannonball);
		cannonball->getBody()->ApplyLinearImpulseToCenter(b2Vec2(cos(this->barrelAngle) * 150,
	                                                             sin(this->barrelAngle) * 150), true);
	}
}


void Cannon::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->spriteSheet->getSprite().setPosition(this->getBody()->GetPosition().x,
	                                          -this->getBody()->GetPosition().y - this->barrelDimensions.y);
	this->spriteSheet->getSprite().setRotation(-this->barrelAngle * 180 / M_PI);
	window->draw(spriteSheet->getSprite());

	this->carriageSprite.setPosition(this->getBody()->GetPosition().x,
	                                -this->getBody()->GetPosition().y);
	this->carriageSprite.setRotation(-this->body->GetAngle() * 180 / M_PI);
	window->draw(carriageSprite);
}
