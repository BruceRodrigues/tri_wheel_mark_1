#ifndef ENGINE_H
#define ENGINE_H

#include "engine/wheel.h"
#include "engine/stateMachine/state.h"

namespace Engine {
    
    class MotorEngine {

    public:
        MotorEngine();
        void setup();
        void update();
        void transitionTo(State* newState);

    private:
        State* currentState;
        Wheel* leftWheel;
        Wheel* rightWheel;
    };
}

#endif