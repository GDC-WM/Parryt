#include <memory>
#include <cmath>
#include <box2d/box2d.h>

#include "actor.hpp"
#include "character.hpp"


Character::Character(b2Vec2 position) : Actor(position) {
	bodyDef.fixedRotation = true;
	this->bodyDef.type = b2_dynamicBody;
	this->maxJumps = 1;
}


bool Character::damage(float damage) {
	this->health -= damage;
	// don't update character's health if at max already
	if (this->health > this->maxHealth) this->health = this->maxHealth;
	if (this->health <= 0) this->kill();
	//TODO Switch to damage sound in the future
	// this->buffer.loadFromFile("../resources/JumpSE.wav");
	// JumpSE.setBuffer(buffer);
	// JumpSE.play();
	return true;
}


void Character::heal(int healAmount) {
	this->health += healAmount;
	if (this->health > this->maxHealth) this->health = this->maxHealth;
}


void Character::stop(void) {
	b2Vec2 velocity = this->body->GetLinearVelocity();
	if (abs(velocity.x) >= 1) {
		float stopForce = -velocity.x / abs(velocity.x) * this->deceleration;
		//TODO: stephen make ^this^ not dumb
		this->body->ApplyForceToCenter(b2Vec2(stopForce, 0), true);
		return;
	}
	// catch micro-oscillation because stephen
	velocity.x = 0;
	this->body->SetLinearVelocity(velocity);
}


bool Character::jump(void) {
	if (this->jumpCounter == this->maxJumps) return false;

	this->body->SetLinearVelocity(b2Vec2(this->body->GetLinearVelocity().x, 0));
	this->body->ApplyLinearImpulseToCenter(b2Vec2(0, this->jumpImpulse), true);

	if (allegiance == glob::Allegiance::parrot) {
		buffer.loadFromFile("../resources/JumpSE.wav");
		JumpSE.setBuffer(buffer);
		JumpSE.play();
	}

	this->jumpCounter++;
	return true;
}


void Character::onCollision(Actor &a) {
	if (a.getAllegiance() == glob::Allegiance::neutral && a.shouldCollide(*this)) this->jumpCounter = 0;
}


void Character::drawHealthBar(std::shared_ptr<sf::RenderWindow> window, float y) {
	sf::RectangleShape healthBar(sf::Vector2f(5.0 * float(this->health) / float(this->getMaxHealth()), 0.2));
	sf::Vector2f position = glob::convertVec(this->getBody()->GetPosition());
	position.x -= 2.5;
	position.y -= y;
	healthBar.setPosition(position);
	healthBar.setFillColor(sf::Color::Red);
	window->draw(healthBar);
}


void Character::update(void) {
	switch (this->movementForceDir) {
		case glob::Dir::left:
			if (this->body->GetLinearVelocity().x > -this->maxSpeed)
				this->body->ApplyForceToCenter(b2Vec2(-this->acceleration, 0), true);
			
			//If relatively fast, be able to stop quickly and go in the other direction
			if (this->body->GetLinearVelocity().x <= this->maxSpeed && this->body->GetLinearVelocity().x > 5) {
				this->lookDir = glob::Dir::left;
				this->body->ApplyForceToCenter(b2Vec2(3 * -this->acceleration, 0), true);
			}
			
			//set look direction
			if (this->body->GetLinearVelocity().x >= -this->maxSpeed && this->body->GetLinearVelocity().x < 0)
				this->lookDir = glob::Dir::left;
			break;
		case glob::Dir::right:
			if (this->body->GetLinearVelocity().x < this->maxSpeed) 
				this->body->ApplyForceToCenter(b2Vec2(this->acceleration, 0), true);
			
			//If relatively fast, be able to stop quickly and go in the other direction
			if (this->body->GetLinearVelocity().x >= -this->maxSpeed && this->body->GetLinearVelocity().x < -5) {
				this->lookDir = glob::Dir::right;
				this->body->ApplyForceToCenter(b2Vec2(3 * this->acceleration, 0), true);
			}
			
			//set look direction
			if (this->body->GetLinearVelocity().x <= this->maxSpeed && this->body->GetLinearVelocity().x > 0)
				this->lookDir = glob::Dir::right;
			break;
		case glob::Dir::none:
			this->stop();
			break;
		default:; // ignore other directions
	}
}
