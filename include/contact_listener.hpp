#ifndef CONTACT_LISTENER_HPP
#define CONTACT_LISTENER_HPP


#include <list>
#include <memory>
#include <box2d/b2_world_callbacks.h>


class ContactListener : public b2ContactListener {
public:
	/**
	 * Called when the two fixtures begin to overlap
	 */
	void BeginContact(b2Contact *contact);

	/**
	 * Called when the two fixtures cease to overlap
	 */
	void EndContact(b2Contact *contact);
};


#endif
