#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <iostream>
#include <list>

#include "actor.hpp"

/*
* The parent class for all movable characters
*/
class Character : public Actor, public std::enable_shared_from_this<Character> {
	protected:
		int maxHealth;
		float health;
		double maxSpeed, jumpSpeed, maxJump, jumpStart;
		bool jumping = false;

	public:
		Character(double x, double y, double width, double height, double mass, double maxSpeed, int maxHealth, float maxJump);

		virtual void damage(float d);

		void heal(int healAmount);

		void setMaxSpeed(double maxSpeed) { this->maxSpeed = maxSpeed; };

		void setHealth(double health) { this->health = health; };

		const int getHealth(void) const { return this->health; };

		void setMaxHealth(double health) { this->maxHealth = health; };

		const int getMaxHealth(void) const { return this->maxHealth; };

		void jump(void);

		void goLeft(void);

		void goRight(void);

		void update(const float &dt) override;
};

#endif
