#ifndef WHEELS_H
#define WHEELS_H

namespace Engine {

    enum Direction {
        RIGHT,
        LEFT
    };

    class Wheels {

    public:
        Wheels();
        void setup();
        void turnRight();
        void turnLeft();
        void forward();
        void backward();
        void reset();


    private: 
        void turn(Direction direction);
    };

}

#endif