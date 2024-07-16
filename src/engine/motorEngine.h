#ifndef ENGINE_H
#define ENGINE_H

#include "engine/wheel.h"

namespace Engine {
    
    class MotorEngine {

    public:
        MotorEngine();
        void setup();
        void setSpeed(int y, int x);

    private:
        Wheel* leftWheel;
        Wheel* rightWheel;
    };
}

#endif