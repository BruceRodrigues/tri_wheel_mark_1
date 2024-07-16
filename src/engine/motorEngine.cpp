#include <Arduino.h>
#include "engine/motorEngine.h"
#include "pins.h"
#include "config.h"
#include "engine/wheel.h"

using namespace Engine;

MotorEngine::MotorEngine() {
    this->leftWheel = new Wheel(PIN_WHEEL_LEFT_FORWARD, PIN_WHEEL_LEFT_BACKWARD, PIN_WHEEL_LEFT_PWM);
    this->rightWheel = new Wheel(PIN_WHEEL_RIGHT_FORWARD, PIN_WHEEL_RIGHT_BACKWARD, PIN_WHEEL_RIGHT_PWM);
}

void MotorEngine::setup() {
    this->leftWheel->setup();
    this->rightWheel->setup();
}

void MotorEngine::setSpeed(int y, int x) {
    if (y < 128) {
        this->rightWheel->forward();
        this->leftWheel->forward();
    } else if (y > 128) {
        this->rightWheel->backward();
        this->leftWheel->backward();
    } else if (y == 128) {
        this->rightWheel->reset();
        this->leftWheel->reset();
    }


    int speed = 0;
    if (y < 128) {
        speed = map(y, 127, 0, 0, 255);
    } else if (y > 128) {
        speed = map(y, 129, 255, 0, 255);
    }


    float rightWheelDiv = 0;
    float leftWheelDiv = 0;

    if (x > 128) {
        rightWheelDiv = map(x, 129, 255, 0, 150);
    } else if (x < 128) {
        leftWheelDiv = map(x, 127, 0, 0, 150);
    }


    this->rightWheel->setSpeed(speed - rightWheelDiv);
    this->leftWheel->setSpeed(speed - leftWheelDiv);
}