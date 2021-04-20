#ifndef VIEW_HPP
#define VIEW_HPP


#include <list>
#include <memory>

#include "actor.hpp"
#include "game_controller.hpp"


class View {
public:
	View(std::shared_ptr<GameController> logic);

	virtual void update(const float &dt) = 0;


protected:
	std::shared_ptr<GameController> logic;
};


#endif
