#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>

#include "contact_filter.hpp"
#include "actor.hpp"


bool ContactFilter::ShouldCollide(b2Fixture *fix1, b2Fixture *fix2) {
	// retrieve the actors
	Actor* actor1 = reinterpret_cast<Actor*>(fix1->GetBody()->GetUserData().pointer);
	Actor* actor2 = reinterpret_cast<Actor*>(fix2->GetBody()->GetUserData().pointer);

	// check that BOTH want to collide, otherwise no collision
	return actor2->collides(*actor1) && actor1->collides(*actor2);
}
