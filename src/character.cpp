#include <memory>
#include <box2d/box2d.h>

#include "actor.hpp"
#include "character.hpp"


Character::Character(float x, float y) : Actor(x, y) {
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
	this->body->SetLinearVelocity(b2Vec2(-10, this->body->GetLinearVelocity().y));
}


void Character::goRight(void) {
	this->body->SetLinearVelocity(b2Vec2(10, this->body->GetLinearVelocity().y));
}


void Character::jump(void) {
	this->body->SetLinearVelocity(b2Vec2(this->body->GetLinearVelocity().x, 10));
}


void Character::update(const float &dt) {
	Actor::update(dt);
}
