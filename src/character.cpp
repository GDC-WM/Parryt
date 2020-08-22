#include <memory>
#include <iostream>
#include <list>

#include "math.h"

#define PI 3.14159265

#include "actor.hpp"
#include "character.hpp"

Character::Character(double x, double y, double width, double height, double mass, double maxSpeed, int maxHealth,
                     float maxJump)
		: Actor(x, y, width, height) {
	this->mass = mass;
	this->maxSpeed = maxSpeed;
	this->health = this->maxHealth = maxHealth;
	this->maxJump = maxJump;
	this->jumpSpeed = 800;
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
	if (this->jumping && (this->getY() > this->maxJump)) this->ySpeed = -this->jumpSpeed;
	if (this->state == ActorState::GROUNDED) {
		this->ySpeed = -this->jumpSpeed;
		this->jumpPosition = this->getY();
	}
	//track original y from jump and checkzx against maxjumpheight
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
	/*check difference between current Y and initialJumpHeight to see if reached maxJump*/
}
