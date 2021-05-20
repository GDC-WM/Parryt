#ifndef ACTOR_HPP
#define ACTOR_HPP


#include <list>
#include <memory>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <iostream>


/*
 * Define what side of the fight that the actor is on
 */
enum class Allegiance { parrot, pirate, neutral };


/*
 * How does this collide?
 */
enum class CollisionID { solid };


/*
 * Define a direction
 */
enum class Dir { front, back, left, right, up, down, none };


/*
 * Base class representing a physical object in the game
 */
class Actor : public std::enable_shared_from_this<Actor> {
public:
	/**
	 * @param position Vector x and y position of the middle of the actor
	 */
	Actor(const b2Vec2 &position);

	/**
	 * @return Const pointer to the body
	 */
	const b2BodyDef &getBodyDef(void) const { return this->bodyDef; };

	/**
	 * @param room Add the actor to the given room
	 */
	void setWorld(std::shared_ptr<b2World> world);

	/**
	 * @return Const pointer to the body
	 */
	const b2Body *getBody(void) const { return this->body; };

	/**
	 * @return Pointer to the body
	 */
	b2Body *getBody(void) { return this->body; };

	/**
	 * @return Allegiance of the actor
	 */
	const Allegiance &getAllegiance(void) const { return this->allegiance; };

	/**
	 * @param allegiance New allegiance of the actor
	 */
	void setAllegiance(const Allegiance &allegiance) { this->allegiance = allegiance; };

	/**
	 * Tell the actor it collided with the given actor
	 *
	 * @param a Actor it collided with
	 */
	virtual void onCollision(Actor &a) {};

	/**
	 * @param a Actor to test collision of
	 * @return Whether this would collide with the given actor
	 */
	virtual const bool shouldCollide(const Actor &a) const { return true; };

	/**
	 * Step the actor forward in time
	 *
	 * @param dt Time forward in milliseconds
	 */
	virtual void update(void) {};

	/**
	 * Tell actor to draw itself
	 *
	 * @param window Window to draw itself on
	 */
	virtual void draw(std::shared_ptr<sf::RenderWindow> window) {};

	/**
	 * @return isTarget
	 */
	const bool &isTargetable() { return this->target; };

	/**
	 * @param targetable True if it is a target, false if not
	 */
	void setTargetable(bool targetable) { this->target = targetable; };

	/**
	 * Mark the actor for removal.
	 */
	void kill(void) { this->dead = true; };

	/**
	 * Check if the actor as marked for removal.
	 */
	const bool &isDead(void) const { return this->dead; };

	/**
	 * @return priority
	 */
	const int &getPriority(void) const{ return this->priority; };

	/**
	 * sets Priority, higher priority actors are drawn first on screen.
	 */
	void setPriority(int priority) {this->priority = priority ;};

	/**
	 * @param damage Amount of damage to do
	 */
	virtual void damage(float damage) {};


protected:
	Allegiance allegiance = Allegiance::neutral;
	b2BodyDef bodyDef;
	b2FixtureDef fixtureDef;
	b2Body *body;
	b2Vec2 dimensions;
	bool target = false;
	bool dead = false;
	int priority = 0;
};


#endif
