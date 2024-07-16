#ifndef WHEEL_H
#define WHEEL_H

namespace Engine {

    class Wheel {

    public:
        Wheel(int forwardPin, int backwardPin, int pwmPin);
        void setup();
        void forward();
        void backward();
        void reset();
        void gas();
        void breaking();
        void turn();
        void setSpeed(int speed);

    private:
        int forwardPin;
        int backwardPin;
        int pwmPin;
        int speed;
    };

}

#endif