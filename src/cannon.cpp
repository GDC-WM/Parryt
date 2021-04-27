#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <list>

#include "cannon.hpp"
#include "cannonball.hpp"
#include "model.hpp"


Cannon::Cannon(b2Vec2 position, std::shared_ptr<Model> model) : Actor(position) {
	this->model = model;
	this->allegiance = Allegiance::pirate;
	this->setPriority(1);

	// fix shape to body
	this->bodyDef.type = b2_staticBody;
	this->bodyDef.enabled = false;
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 1.0f;
	this->fixtureDef.friction = 0.3f;

	// set carriage
	carriageTexture.loadFromFile("../resources/cannon-carriage.png");
	this->carriageSprite = sf::Sprite(carriageTexture, sf::IntRect(0,0,64,64));
	carriageSprite.setScale(0.08, 0.08);
	this->carriageSprite.setOrigin(this->WIDTH * 14, this->HEIGHT * 14 - 10);

	// set barrel
	barrelTexture.loadFromFile("../resources/cannon-barrel.png");
	this->barrelSprite = sf::Sprite(barrelTexture, sf::IntRect(0,0,64,64));
	barrelSprite.setScale(0.08, 0.08);
	this->barrelSprite.setOrigin(15, 21.5);

	// set old carriage
	this->carriage.setOrigin(this->WIDTH, this->HEIGHT);
	this->carriage.setFillColor(sf::Color::Red);
	this->carriage.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));

	// set old barrel
	this->barrel.setOrigin(0, this->barrelDimensions.y);
	this->barrel.setFillColor(sf::Color::White);
	this->barrel.setSize(sf::Vector2f(this->barrelDimensions.x * 2, this->barrelDimensions.y * 2));
}


void Cannon::shoot(void) {
	if (this->loadingCounter > 0) return;

	this->loadingCounter = this->LOAD_TIME;
	std::shared_ptr<Cannonball> cannonball = std::make_shared<Cannonball>(this->body->GetPosition(), 20);
	this->model->addActor(cannonball);
	cannonball->getBody()->ApplyLinearImpulseToCenter(b2Vec2(cos(this->barrelAngle) * 150,
	                                                         sin(this->barrelAngle) * 150), true);
}


void Cannon::update(void) {
	// update barrel angle
	this->barrelAngle += this->rotationVelocity;
	if (this->barrelAngle < this->minAngle) this->barrelAngle = this->minAngle;
	if (this->barrelAngle > this->maxAngle) this->barrelAngle = this->maxAngle;
	if (this->loadingCounter > 0) this->loadingCounter--;
}


void Cannon::draw(std::shared_ptr<sf::RenderWindow> window) {
	this->carriage.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);
	this->carriage.setRotation(-this->body->GetAngle() * 180 / M_PI);
	//window->draw(carriage);

	this->barrel.setPosition(this->getBody()->GetPosition().x,
	                        -this->getBody()->GetPosition().y);
	this->barrel.setRotation(-this->barrelAngle * 180 / M_PI);
	//window->draw(barrel);

	this->barrelSprite.setPosition(this->getBody()->GetPosition().x,
	                              -this->getBody()->GetPosition().y - this->barrelDimensions.y);
	this->barrelSprite.setRotation(-this->barrelAngle * 180 / M_PI);
	window->draw(barrelSprite);

	this->carriageSprite.setPosition(this->getBody()->GetPosition().x,
	                                -this->getBody()->GetPosition().y);
	this->carriageSprite.setRotation(-this->body->GetAngle() * 180 / M_PI);
	window->draw(carriageSprite);
}
