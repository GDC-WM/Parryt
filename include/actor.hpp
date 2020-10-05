#ifndef ACTOR_H
#define ACTOR_H

#include <memory>
#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>


/*
 * Base class that all actors in the game inherit from
 */
class Actor {
	protected:
		b2BodyDef bodyDef;
		b2FixtureDef fixtureDef;
		b2Body *body;
		sf::RectangleShape drawable;
		std::shared_ptr<b2World> world;


	public:
		Actor(float x, float y);

		b2BodyDef &getBodyDef(void) { return this->bodyDef; };

		void setWorld(std::shared_ptr<b2World> world);

		b2Body *getBody(void) { return this->body; };

		void setDrawablePos(const double &x, const double &y) { this->drawable.setPosition(x, y); };

		/**
		 * Return drawable.
		 */
		virtual const sf::Shape &getDrawable(void) const { return this->drawable; };

		virtual void update(const float &dt);

		virtual ~Actor() { this->world->DestroyBody(this->body); }
};


#endif
