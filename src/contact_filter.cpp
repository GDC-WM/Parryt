#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>

#include "contact_filter.hpp"
#include "actor.hpp"


bool b2ContactFilter::ShouldCollide(b2Fixture *fix1, b2Fixture *fix2) {
	Actor* actor1 = (Actor*)fix1->GetUserData().pointer;
	Actor* actor2 = (Actor*)fix2->GetUserData().pointer;
	return actor1->collides(*actor2);
}
