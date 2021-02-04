#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>

#include "contact_filter.hpp"
#include "actor.hpp"
#include "exit.hpp"
#include "platform.hpp"
#include "wall.hpp"
#include "character.hpp"
#include "pari.hpp"
#include "cannon.hpp"
#include "cannonball.hpp"
#include "mast.hpp"


bool b2ContactFilter::ShouldCollide(b2Fixture *fix1, b2Fixture *fix2) {
	Actor* actor1 = (Actor*)fix1->GetUserData().pointer;
	Actor* actor2 = (Actor*)fix2->GetUserData().pointer;
	return true;
}
