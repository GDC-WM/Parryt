#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <memory>

#include "actor.hpp"
#include "master_logic.hpp"

class View {
    protected:
        std::shared_ptr<MasterLogic> logic;

    public:
        View(std::shared_ptr<MasterLogic> logic);

        virtual void update(const float &dt) = 0;
};

#endif
