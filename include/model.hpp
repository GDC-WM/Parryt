#ifndef MODEL_HPP
#define MODEL_HPP


#include <list>
#include <memory>
#include <box2d/box2d.h>
#include <queue>

#include "contact_filter.hpp"
#include "contact_listener.hpp"


class Actor;

/**
 * comparator function for shared pointers
 */
struct SharedComparator {
    template <typename T>
    bool operator()(const std::shared_ptr<T>& lhs,
                    const std::shared_ptr<T>& rhs) const
    {
        return (*lhs) < (*rhs);
    }
};

/**
 * priority queue for actors to be drawn in correct order
 */
typedef std::priority_queue<std::shared_ptr<Actor>, std::vector<std::shared_ptr<Actor>>, SharedComparator> ActorPriorityQueue;

/*
 * A physical space containing a list of all of the actors
 */
class Model : public std::enable_shared_from_this<Model> {
public:
	Model(void);

	/**
	 * Return the world
	 */
	const std::shared_ptr<b2World> getWorld(void) const { return this->world; };

	/**
	 * Return the list of actors.
	 */
	const std::list<std::shared_ptr<Actor>> &getActorList(void) { return this->actorList; };

	/**
	 * @return actorPriorityQueue
	 */
	const ActorPriorityQueue &getActorPriorityQueue(void) {return this -> actorPriorityQueue; };

	/**
	 * Add an actor to the list
	 *
	 * @param actor Actor to add
	 */
	void addActor(std::shared_ptr<Actor> actor);

	void reset(void);

	void update(void);





private:
	std::shared_ptr<b2World> world;
	std::list<std::shared_ptr<Actor>> actorList;
  ActorPriorityQueue actorPriorityQueue;
	ContactFilter contact_filter;
	ContactListener contact_listener;
};


#endif
