#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "actor.hpp"
#include "character.hpp"
#include "pari.hpp"
#include "sprite_sheet.hpp"


Pari::Pari(b2Vec2 position) : Character(position) {
	this->allegiance = Allegiance::parrot;
	this->setTargetable(true);

	this->acceleration = 10;
	this->deceleration = 250;
	this->jumpImpulse = 235;
	this->maxSpeed = 15;
	this->maxHealth = 100;
	this->maxJumps = 2;
	this->parryDuration = std::chrono::milliseconds(200);
	this->parryRechargeDuration = std::chrono::seconds(1);
	// set parry start so Pari can parry right away
	this->parryStart = std::chrono::steady_clock::now() - this->parryRechargeDuration;

	// fix shape to body
	this->shape.SetAsBox(this->WIDTH, this->HEIGHT);
	this->fixtureDef.shape = &this->shape;
	this->fixtureDef.density = 2.4f;
	this->fixtureDef.friction = 0.0f;

	// load pari spritesheet
	this->spriteSheet = std::make_unique<SpriteSheet>("../resources/pari.png", sf::Vector2i(64, 64));
	this->spriteSheet->setLoop(this->standLoop);

	// set drawable
	this->sprite = sf::Sprite(texture, sf::IntRect(0,0,64,64));
	this->sprite.setScale(0.08,0.08); //hardcoding bad
	this->sprite.setOrigin(32 * .08, 32 * .08);

	// set old drawable
	this->drawable.setOrigin(this->WIDTH, this->HEIGHT);
	this->drawable.setFillColor(sf::Color::Green);
	this->drawable.setSize(sf::Vector2f(this->WIDTH * 2, this->HEIGHT * 2));
}


bool Pari::jump(void) {
	bool jumped = Character::jump();
	if (jumped) this->spriteSheet->setOneShot(this->jumpLoop);
	// prevents too many jumps
	return jumped;
}


bool Pari::parry(float angle) {
	if (!this->canParry()) return false;

	this->parryAngle = angle;
	this->parryStart = std::chrono::steady_clock::now();
	return true;
}


void Pari::onCollision(Actor &a) {
	if (a.getAllegiance() == Allegiance::neutral && a.shouldCollide(*this)) this->jumpCounter = 0;

	if (this->isParrying()) {
		// deflect contact object
		b2Vec2 projectileVelocity = a.getBody()->GetLinearVelocity();
		double projectileSpeed = sqrt(pow(projectileVelocity.x, 2) + pow(projectileVelocity.y, 2));
		a.getBody()->SetLinearVelocity(b2Vec2(projectileSpeed * cos(this->parryAngle),
		                                      projectileSpeed * sin(this->parryAngle)));

		// recoil Pari
		this->getBody()->SetLinearVelocity(b2Vec2(-10, -10));
	}
}


void Pari::draw(std::shared_ptr<sf::RenderWindow> window) {
	// old drawable
	this->drawable.setPosition(this->getBody()->GetPosition().x,
	                          -this->getBody()->GetPosition().y);

	//window->draw(drawable);

	// set animation
	Loop newLoop;
	if (abs(this->body->GetLinearVelocity().x) > 0.1) {
		newLoop = this->runLoop; //hardcoding bad
	}
	else newLoop = this->standLoop;

	// use mirrored sprite if facing left
	this->spriteSheet->setMirrored(this->lookDir == Dir::left);
	//TODO: ^this check could be removed if all characters were given a spritesheet

	if (newLoop != this->spriteSheet->getLoop()) {
		this->spriteSheet->setLoop(newLoop);
		this->spriteSheet->restart();
	}

	this->spriteSheet->getSprite().setPosition(this->body->GetPosition().x - 32 * .08,
	                                          -this->body->GetPosition().y - 32 * .08 - 0.5);

	window->draw(this->spriteSheet->getSprite());
}
