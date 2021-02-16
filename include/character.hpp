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

		virtual void damage(float d);

		void heal(int healAmount);

		void setHealth(double health) { this->health = health; };

		const int getHealth(void) const { return this->health; };

		void setMaxHealth(double health) { this->maxHealth = health; };

		const int getMaxHealth(void) const { return this->maxHealth; };

		virtual bool jump(void);

		void goLeft(void);

		void goRight(void);

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
