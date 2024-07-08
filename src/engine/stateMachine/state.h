#ifndef STATE_H
#define STATE_H

#include "engine/motorEngine.h"

namespace Engine {

    class State {

        public:
            virtual void enter(Wheel* rightWheel, Wheel* leftWheel) {};
            virtual void execute(Wheel* rightWheel, Wheel* leftWheel) = 0;
            virtual void exit(Wheel* rightWheel, Wheel* leftWheel) {};

        protected:
            State() = default;
            virtual ~State() = default;
    };
}


#endif