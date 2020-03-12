#include <memory>
#include <iostream>
#include <list>

#include "math.h"

#define PI 3.14159265

#include "actor.h"
#include "character.h"

Character::Character(double x, double y, double width, double height, double mass, double maxSpeed, int maxHealth,
					 float maxJump)
		: Actor(x, y, width, height) {
	this->mass = mass;
	this->maxSpeed = maxSpeed;
	this->health =
	this->maxHealth = maxHealth;
	this->maxJump = maxJump;
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
	this->xSpeed -= this->xSpeed >= -150 ? 1 : 0.5;
}

void Character::goRight(void) {
	this->xSpeed += this->xSpeed <= 150 ? 1 : 0.5;
}

void Character::jump(void) {
	if (this->jumping) { this->ySpeed -= this->maxJump*.35; }
	//track original y from jump and checks against maxjumpheight
	//limit goRight and goLeft functions while jumping?
}

void Character::update(const float &dt) {
	Actor::update(dt);
	if (this->xSpeed < 0) this->xSpeed += 0.3;
	if (this->xSpeed > 0) this->xSpeed -= 0.3;
	if (this->getY() < 335) this->ySpeed += 0.4 * this->mass;
	else if (this->getY() >= 335) {
		ySpeed = 0;
		this->jumping = true;
	}
}
