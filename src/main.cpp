
#include <Arduino.h>
#include "pins.h"
#include "engine/motorEngine.h"
#include "input/controller.h"
#include <Ticker.h>

using namespace Engine;
using namespace Input;

MotorEngine motorEngine;
int rx, ry, lx, ly;

int light = 0;
int rightIndicator = 0;
int leftIndicator = 0;

void blinkRightLight() {
    digitalWrite(PIN_RIGHT_INDICATOR_LIGHT, !digitalRead(PIN_RIGHT_INDICATOR_LIGHT));
}

Ticker rightLightTicker(blinkRightLight, 500);

void onRightJoyChanged(int x, int y) {
    rx = x;
    ry = y;
}

void onLeftJoyChanged(int x, int y) {
    lx = x;
    ly = y;
}

void onButtonPressed(uint16_t button) {
    if (button == 16384) { // X
        light = !light;
    }
    if (button == 2048) { // R1
        rightIndicator = !rightIndicator;
    } 
    if (button == 1024) { // L1
        leftIndicator = !leftIndicator;
    }

    Serial.println(button);
    digitalWrite(PIN_LEFT_INDICATOR_LIGHT, leftIndicator);
    digitalWrite(PIN_RIGHT_INDICATOR_LIGHT, rightIndicator);
    digitalWrite(PIN_LIGHT, light);
}

Controller controller(onRightJoyChanged, onLeftJoyChanged, onButtonPressed);

void setup() {
    Serial.begin(9600);
    motorEngine.setup();
    controller.setup();

    pinMode(PIN_LIGHT, OUTPUT);
    pinMode(PIN_RIGHT_INDICATOR_LIGHT, OUTPUT);
    pinMode(PIN_LEFT_INDICATOR_LIGHT, OUTPUT);

    rightLightTicker.start();
}


void loop() {
    controller.read();
    motorEngine.setSpeed(ly, rx);

    if (rightIndicator) {
        rightLightTicker.update();
    }
}

