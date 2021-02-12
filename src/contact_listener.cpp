#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>

#include "contact_listener.hpp"
#include "actor.hpp"
#include "exit.hpp"
#include "platform.hpp"
#include "wall.hpp"
#include "character.hpp"
#include "pari.hpp"
#include "cannon.hpp"
#include "cannonball.hpp"
#include "mast.hpp"


void ContactListener::BeginContact(b2Contact *contact) {
	Actor* actor1 = (Actor*)contact->GetFixtureA()->GetUserData().pointer;
	Actor* actor2 = (Actor*)contact->GetFixtureB()->GetUserData().pointer;
}
