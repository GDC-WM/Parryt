#ifndef CONTACT_FILTER_HPP
#define CONTACT_FILTER_HPP


#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>


class ContactFilter : public b2ContactFilter {
	public:
		/**
		 * @return whether the passed fixtures should collide
		 */
		bool ShouldCollide(b2Fixture *fixa, b2Fixture *fixb) override;
};


#endif
