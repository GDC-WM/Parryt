#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include <memory>
#include <box2d/box2d.h>

#include "actor.hpp"

/*
* The parent class for all movable characters
*/
class Character : public Actor, public std::enable_shared_from_this<Character> {
public:
	Character(b2Vec2 position);

	/**
	 * @param damage Amount of damage to do
	 */
	virtual void damage(float damage);

	/**
	 * @param healAmount Amount to heal
	 */
	void heal(int healAmount);

	/**
	 * @param health new health
	 */
	void setHealth(double health) { this->health = health; };

	/**
	 * @return Current health
	 */
	const int getHealth(void) const { return this->health; };

	/**
	 * @param health Current max health
	 */
	void setMaxHealth(double health) { this->maxHealth = health; };

	/**
	 * @return Current max health
	 */
	const int getMaxHealth(void) const { return this->maxHealth; };

	/**
	 * Make the character jump
	 */
	virtual bool jump(void);

	/**
	 * Make the character go left
	 */
	void goLeft(void);

	/**
	 * Make the character go left
	 */
	void goRight(void);

	/**
	 * Make the character go left
	 */
	void stop(void);

	void collide(Actor &a) override;

	/**
	 * @return if the character is resting on the ground
	 */
	const bool &isGrounded(void);


protected:
	Direction lookDirection = Direction::RIGHT;
	float jumpImpulse;
	int maxJumps;
	int jumpCounter = 0;
	float acceleration;
	float deceleration;
	float maxSpeed;
	int maxHealth;
	float health;
	//TODO: give every character a SpriteSheet?
};


#endif
