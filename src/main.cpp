
#include <Arduino.h>
#include "pins.h"
#include "engine/motorEngine.h"
#include "engine/stateMachine/engineStates.h"
#include "input/controller.h"

using namespace Engine;
using namespace Input;

int joyRightX = 0;
int joyRightY = 0;
int joyLeftX = 0;
int joyLeftY = 0;
int buttonPressed = 0;

void onRightJoyChanged(int x, int y) {
    joyRightX = x;
    joyRightY = y;
}

void onLeftJoyChanged(int x, int y) {
    joyLeftX = x;
    joyLeftY = y;
    Serial.print("JoyLeftX: ");
    Serial.print(joyLeftX);
    Serial.print(" JoyLeftY: ");
    Serial.println(joyLeftY);
}

void onButtonPressed(int button) {
    buttonPressed = button;
}

MotorEngine motorEngine;
Controller controller(onRightJoyChanged, onLeftJoyChanged, onButtonPressed);

void setup() {
    Serial.begin(9600);
    motorEngine.setup();
    controller.setup();
}


void loop() {
    if (joyLeftY < 128)  {
        motorEngine.transitionTo(Gas::getInstance());
    } else if (joyLeftY == 128) {
        motorEngine.transitionTo(Breaking::getInstance());
    } else if (joyLeftY > 128) {
        motorEngine.transitionTo(Reverse::getInstance());
    }

    controller.read();
    delay(500);
    motorEngine.update();
    delay(500);
}

