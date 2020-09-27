#include <memory>
#include <iostream>
#include <list>

#include "math.h"

#define PI 3.14159265

#include "actor.hpp"
#include "character.hpp"

Character::Character(float x, float y) : Actor(x, y) {
	this->bodyDef.type = b2_kinematicBody;
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
}

void Character::goRight(void) {
}

void Character::jump(void) {
}

void Character::update(const float &dt) {
	Actor::update(dt);
}
