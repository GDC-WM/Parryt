#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <memory>

#include "actor.h"
#include "master_logic.h"

class View {
    protected:
        std::shared_ptr<MasterLogic> logic;

    public:
        View(std::shared_ptr<MasterLogic> logic);

        virtual void update(float delta) = 0;
};

#endif
