
#include <Arduino.h>
#include "pins.h"
#include "engine/motorEngine.h"
#include "input/controller.h"

using namespace Engine;
using namespace Input;

MotorEngine motorEngine;
int rx, ry, lx, ly;

void onRightJoyChanged(int x, int y) {
    rx = x;
    ry = y;
}

void onLeftJoyChanged(int x, int y) {
    lx = x;
    ly = y;
}

void onButtonPressed(int button) {
    // TODO: implement
}

Controller controller(onRightJoyChanged, onLeftJoyChanged, onButtonPressed);

void setup() {
    Serial.begin(9600);
    motorEngine.setup();
    controller.setup();
}


void loop() {
    controller.read();
    motorEngine.setSpeed(ly, rx);
}

