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


void Character::damage(float d) {
	this->health -= d;
	if (this->health > this->maxHealth) this->health = this->maxHealth;
	if (this->health < 0) this->health = 0;
}


void Character::heal(int healAmount) {
	this->health += healAmount;
	if (this->health > this->maxHealth) this->health = this->maxHealth;
}


void Character::goLeft(void) {
	if (this->body->GetLinearVelocity().x > -this->maxSpeed) {
		this->body->ApplyForceToCenter(b2Vec2(-this->acceleration, 0), true);
	}
	this->lookDirection = Direction::LEFT;
}


void Character::goRight(void) {
	if (this->body->GetLinearVelocity().x < this->maxSpeed) {
		this->body->ApplyForceToCenter(b2Vec2(this->acceleration, 0), true);
	}
	this->lookDirection = Direction::RIGHT;
}


void Character::stop(void) {
	b2Vec2 velocity = this->body->GetLinearVelocity();
	if (abs(velocity.x) >= 0.3) {
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
	this->jumpCounter++;
	return true;
}


bool Character::collide(Actor &a) {
	if (a.getAllegiance() == Allegiance::NEUTRAL
	 && a.collides(*this)) this->jumpCounter = 0;
	return this->collides(a);
}


const bool &Character::isGrounded(void) {
}
