#ifndef CONTACT_FILTER_HPP
#define CONTACT_FILTER_HPP


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


class ContactFilter : public b2ContactFilter {
	public:
		bool ShouldCollide(b2Fixture *fixa, b2Fixture *fixb) override;
};


#endif
