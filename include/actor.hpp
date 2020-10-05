#ifndef ACTOR_H
#define ACTOR_H


#include <memory>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <iostream>


/*
 * Base class that all actors in the game inherit from
 */
class Actor {
	protected:
		std::shared_ptr<b2World> world;
		b2BodyDef bodyDef;
		b2FixtureDef fixtureDef;
		b2Body *body;
		b2PolygonShape shape;

		sf::RectangleShape drawable;


	public:
		/**
		 * y and x Position of the middle of the actor
		 */
		Actor(float x, float y);

		b2BodyDef &getBodyDef(void) { return this->bodyDef; };

		void setWorld(std::shared_ptr<b2World> world);

		b2Body *getBody(void) { return this->body; };

		/**
		 * Update and return drawable.
		 */
		virtual const sf::Shape &getDrawable(void) { this->updateDrawable(); return this->drawable; };

		/**
		 * Update drawable based on the state of the body
		 */
		void updateDrawable(void);

		virtual void update(const float &dt);

		virtual ~Actor() { this->world->DestroyBody(this->body); }
};


#endif
