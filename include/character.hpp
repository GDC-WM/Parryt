#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include <memory>
#include <box2d/box2d.h>
#include <SFML/Audio.hpp>

#include "actor.hpp"


/*
* The parent class for all movable characters
*/
class Character : public Actor, public std::enable_shared_from_this<Character> {
public:
	Character(b2Vec2 position);

	/**
	 * @param damage Amount of damage to do
	 *
	 * @return whether the item took damage or not
	 */
	virtual bool damage(float damage) override;

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
	 * @return look direction
	 */
	glob::Dir getLookDir() { return this->lookDir; };

	/**
	 * Make the character jump
	 */
	virtual bool jump(void);

	/**
	 * Set movement direction
	 */
	void setMovement(const glob::Dir &dir) { this->movementForceDir = dir; };

	/**
	 * Get movement direction
	 */
	const glob::Dir &getMovement(void) const { return this->movementForceDir; };

	virtual void onCollision(Actor &a) override;

	virtual void update(void) override;


protected:
	glob::Dir lookDir = glob::Dir::right;
	glob::Dir movementForceDir = glob::Dir::none;
	float jumpImpulse;
	int maxJumps;
	int jumpCounter = 0;
	float acceleration;
	float deceleration;
	float maxSpeed;
	int maxHealth;
	float health;
	sf::SoundBuffer buffer;
	sf::Sound JumpSE;
	//TODO: give every character a SpriteSheet?

	/**
	 * Make the character apply a stop force
	 */
	void stop(void);

	/**
	 * Tell actor to draw its health bar
	 *
	 * @param window Window to draw itself on
	 */
	virtual void drawHealthBar(std::shared_ptr<sf::RenderWindow> window, float y);
};


#endif
