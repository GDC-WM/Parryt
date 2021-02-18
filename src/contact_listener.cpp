#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>

#include "contact_listener.hpp"
#include "actor.hpp"


void ContactListener::BeginContact(b2Contact *contact) {
	// retrieve the actors
	Actor* actor1 = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	Actor* actor2 = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

	// tell the actors that they have collided
	actor2->collide(*actor1);
	actor1->collide(*actor2);
}


void ContactListener::EndContact(b2Contact *contact) {}
