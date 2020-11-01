#include <memory>
#include <box2d/box2d.h>

#include "actor.hpp"
#include "character.hpp"


Character::Character(float x, float y) : Actor(x, y) {
	bodyDef.fixedRotation = true;
	this->bodyDef.type = b2_dynamicBody;
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
}


void Character::goRight(void) {
	if (this->body->GetLinearVelocity().x < this->maxSpeed) {
		this->body->ApplyForceToCenter(b2Vec2(this->acceleration, 0), true);
	}
}


void Character::jump(void) {
	this->body->SetLinearVelocity(b2Vec2(this->body->GetLinearVelocity().x, 0));
	this->body->ApplyLinearImpulseToCenter(b2Vec2(0, this->jumpImpulse), true);
}
