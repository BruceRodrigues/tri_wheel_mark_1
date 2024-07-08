#include <Arduino.h>
#include "pins.h"
#include "engine/motorEngine.h"

using namespace Engine;

MotorEngine motorEngine;

void setup() {
    Serial.begin(9600);
    motorEngine.setup();
}


void loop() {

}

