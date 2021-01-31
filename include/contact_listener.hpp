#ifndef CONTACT_LISTENER_HPP
#define CONTACT_LISTENER_HPP


#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>

#include "actor.hpp"
#include "exit.hpp"
#include "platform.hpp"
#include "wall.hpp"
#include "character.hpp"
#include "pari.hpp"
#include "cannon.hpp"
#include "cannonball.hpp"
#include "mast.hpp"


class ContactListener : public b2ContactListener {
	public:
		void BeginContact(b2Contact *contact);

		void EndContact(b2Contact *contact);
};


#endif
