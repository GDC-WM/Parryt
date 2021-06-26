#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "grunt.hpp"
#include "bullet.hpp"
#include "model.hpp"


Grunt::Grunt(b2Vec2 position, std::shared_ptr<Model> model) : Character(position) {
	this->model = model;
	this->allegiance = Allegiance::pirate;
	this->priority = 30;
	this->setTargetable(true);

	this->acceleration = 10;
	this->deceleration = 250;
	this->jumpImpulse = 200;
	this->maxSpeed = 15;
	this->health = this->maxHealth = 100;
	this->maxJumps = 1;

	this->bodyDef.fixedRotation = true;
	this->bodyDef.type = b2_dynamicBody;

	// fix shape to body
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 2.0f;
	this->fixtureDef.friction = 1.0f;

	// set drawable
	this->texture.loadFromFile("../resources/pirate.png");
	this->sprite = sf::Sprite(this->texture, sf::IntRect(0,0,64,64));
	this->sprite.setScale(0.08,0.08); //hardcoding BAD
	this->sprite.setOrigin(8, 30);

	//set old drawable
	this->drawable.setOrigin(this->WIDTH, this->HEIGHT);
	this->drawable.setFillColor(sf::Color::Red);
	this->drawable.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));
}


void Grunt::shoot() {
	//check if grunt reloading
	//should we make it that he can shoot x times in a row and then pauses to reload (more realistic)
	if (this->bulletCounter <= 0) {
		this->reloadCounter = this->reloadTime;
		return;
	}
	if (this->reloadCounter > 0 || this->fireRateCounter > 0) return;

	this->fireRateCounter = this->fireRate;
	this->bulletCounter--;

	int correction = 0;
	if (this->shootDir.x < 0) correction++;

	b2Vec2 newVec = this->body->GetPosition();
	newVec.x -= correction;

	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(newVec, 50);
	this->model->addActor(bullet); // give actors access to the room they are in

	this->shootDir.x *= 150;
	this->shootDir.y *= 150;

	bullet->getBody()->ApplyLinearImpulseToCenter(this->shootDir, true); //not fast enough smh
}


void Grunt::draw(std::shared_ptr<sf::RenderWindow> window) {
	// old drawable
	this->drawable.setPosition(convertVec(this->getBody()->GetPosition()));
	//window->draw(drawable);

	// For now we just draw the static image.
	this->sprite.setPosition(convertVec(this->getBody()->GetPosition()));
	this->drawHealthBar(window, 5);

	window->draw(this->sprite);
}


void Grunt::update(void){
	Character::update();

	if (this->fireRateCounter > 0) {
		this->fireRateCounter--;
	}
	if (this->reloadCounter == 0) {
		this->bulletCounter = this->chamberSize;
	}
	if (this->reloadCounter > 0) {
		this->reloadCounter--;
	}
}
