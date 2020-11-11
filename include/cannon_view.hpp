#ifndef CANNON_VIEW_HPP
#define CANNON_VIEW_HPP


#include <list>
#include <memory>

#include "master_logic.hpp"
#include "view.hpp"
#include "actor.hpp"
#include "cannon.hpp"


/**
 * Draw the screen for the player
 */
class CannonView : public View {
	public:
		CannonView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Cannon> cannon);

		void update(const float &dt) override;


	private:
		std::shared_ptr<MasterLogic> logic;
		std::shared_ptr<Cannon> cannon;
};


#endif
