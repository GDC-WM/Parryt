#ifndef ACTOR_HPP
#define ACTOR_HPP


#include <list>
#include <memory>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "room.hpp"


/*
 * Define what side of the fight that the actor is on
 */
enum class Allegiance { PARROT, PIRATE, NEUTRAL };


/*
 * Define a direction
 */
enum class Direction { FRONT, BACK, LEFT, RIGHT, UP, DOWN };


/*
 * Base class that all actors in the game inherit from
 */
class Actor : public std::enable_shared_from_this<Actor> {
	public:
		/**
		 * y and x Position of the middle of the actor
		 */
		Actor(b2Vec2 position);

		b2BodyDef &getBodyDef(void) { return this->bodyDef; };

		void setRoom(std::shared_ptr<Room> room);

		/**
		 * @return const pointer to the body
		 */
		const b2Body *getBody(void) const { return this->body; };

		/**
		 * @return pointer to the body
		 */
		b2Body *getBody(void) { return this->body; };

		const Allegiance &getAllegiance(void) const { return this->allegiance; };

		void setAllegiance(Allegiance allegiance) { this->allegiance = allegiance; };

		virtual void update(const float &dt) {};

		/**
		 * Tell actor to draw itself
		 */
		virtual void draw(std::shared_ptr<sf::RenderWindow> window) {};

		virtual ~Actor() { this->room->getWorld()->DestroyBody(this->body); }


	protected:
		Allegiance allegiance = Allegiance::NEUTRAL; // neutral default
		std::shared_ptr<Room> room;
		b2BodyDef bodyDef;
		b2FixtureDef fixtureDef;
		b2Body *body;
		b2Vec2 dimensions;
};


#endif
