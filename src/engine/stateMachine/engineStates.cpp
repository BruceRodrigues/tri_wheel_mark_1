#include <Arduino.h>
#include "engine/stateMachine/engineStates.h"

using namespace Engine;

void Idle::execute(Wheel* rightWheel, Wheel* leftWheel) {
    rightWheel->reset();
    leftWheel->reset();
}

void Gas::execute(Wheel* rightWheel, Wheel* leftWheel) {
    Serial.print("Gas");
    leftWheel->forward();
    rightWheel->forward();
    leftWheel->gas();
    rightWheel->gas();
}

void Breaking::execute(Wheel* rightWheel, Wheel* leftWheel) {
    rightWheel->breaking();
    leftWheel->breaking();
}

void TurnRightGasing::execute(Wheel* rightWheel, Wheel* leftWheel) {
    leftWheel->forward();
    rightWheel->breaking();
}

void TurnLeftGasing::execute(Wheel* rightWheel, Wheel* leftWheel) {
    rightWheel->forward();
    leftWheel->breaking();
}

void TurnRightBreaking::execute(Wheel* rightWheel, Wheel* leftWheel) {
    rightWheel->breaking();
}

void TurnLeftBreaking::execute(Wheel* rightWheel, Wheel* leftWheel) {
    leftWheel->breaking();
}

void Reverse::execute(Wheel* rightWheel, Wheel* leftWheel) {
    leftWheel->backward();
    rightWheel->backward();
}

