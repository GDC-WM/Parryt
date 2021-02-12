#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>

#include "contact_filter.hpp"
#include "actor.hpp"


bool b2ContactFilter::ShouldCollide(b2Fixture *fix1, b2Fixture *fix2) {
	Actor* actor1 = reinterpret_cast<Actor*>(fix1->GetBody()->GetUserData().pointer);
	Actor* actor2 = reinterpret_cast<Actor*>(fix2->GetBody()->GetUserData().pointer);
	return actor2->collides(*actor1) && actor1->collides(*actor2);
}
