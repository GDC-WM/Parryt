#ifndef CONTACT_FILTER_HPP
#define CONTACT_FILTER_HPP


#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>


class ContactFilter : public b2ContactFilter {
	public:
		bool ShouldCollide(b2Fixture *fixa, b2Fixture *fixb) override;
};


#endif
