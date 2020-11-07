#ifndef ACTOR_HPP
#define ACTOR_HPP


#include <memory>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <iostream>


/*
 * Define what side of the fight that the actor is on
 */
enum class Allegiance { PARROT, PIRATE, NEUTRAL };


/*
 * Base class that all actors in the game inherit from
 */
class Actor {
	public:
		/**
		 * y and x Position of the middle of the actor
		 */
		Actor(b2Vec2 position);

		b2BodyDef &getBodyDef(void) { return this->bodyDef; };

		void setWorld(std::shared_ptr<b2World> world);

		b2Body *getBody(void) { return this->body; };

		const Allegiance &getAllegiance(void) const { return this->allegiance; };

		/**
		 * Return drawable.
		 */
		virtual const sf::Shape &getDrawable(void) { return this->drawable; };

		/**
		 * Update drawable based on the state of the body
		 */
		void updateDrawable(void);

		const sf::Vector2f getDrawableCenter(void) const;

		virtual void update(const float &dt);

		virtual ~Actor() { this->world->DestroyBody(this->body); }


	protected:
		Allegiance allegiance = Allegiance::NEUTRAL; // neutral default
		std::shared_ptr<b2World> world;
		b2BodyDef bodyDef;
		b2FixtureDef fixtureDef;
		b2Body *body;
		b2PolygonShape shape;
		b2Vec2 dimensions;

		sf::RectangleShape drawable;
};


#endif
