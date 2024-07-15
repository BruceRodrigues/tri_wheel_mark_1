#ifndef MOTOR_ENGINE_TEST_H
#define MOTOR_ENGINE_TEST_H

#include <Arduino.h>
#include "engine/wheel.h"
#include "engine/stateMachine/engineStates.h"

using namespace Engine;

void stayStill(Wheel* leftWheel, Wheel* rightWheel) {
    Serial.println("Stay Still");

    Serial.println("Testing Idle State");
    State* state = Idle::getInstance();

    state->enter(rightWheel, leftWheel);
    state->execute(rightWheel, leftWheel);
    state->exit(rightWheel, leftWheel);

    delay(2000);

    Serial.println("Test Complete");
}

void gasToMaximumAndBreakUntilStop(Wheel* leftWheel, Wheel* rightWheel) {
    Serial.println("Gas to Maximum and Break Until Stop");

    Serial.println("Testing Gas State");
    State* state = Gas::getInstance();

    state->enter(rightWheel, leftWheel);
    state->execute(rightWheel, leftWheel);
    state->exit(rightWheel, leftWheel);
    state->enter(rightWheel, leftWheel);
    state->execute(rightWheel, leftWheel);
    state->exit(rightWheel, leftWheel);
    state->enter(rightWheel, leftWheel);
    state->execute(rightWheel, leftWheel);
    state->exit(rightWheel, leftWheel);

    int count = 20;
    for (int i = 0; i < count; i++) {
        Serial.print("Adding Gas ");
        Serial.println(i);
        delay(1000);
        state->execute(rightWheel, leftWheel);
    }

    delay(10000);


    Serial.println("Testing Breaking State");
    state = Breaking::getInstance();

    state->enter(rightWheel, leftWheel);
    state->execute(rightWheel, leftWheel);
    state->exit(rightWheel, leftWheel);

    for (int i = 0; i < count; i++) {
        Serial.print("Breaking ");
        Serial.println(i);
        delay(1000);
        state->execute(rightWheel, leftWheel);
    }

    Serial.println("Test Complete");
}

void testGasingTurningRight(Wheel* leftWheel, Wheel* rightWheel) {

    Serial.println("Testing TurnRightGasing State");
    State* state = Gas::getInstance();

    state->enter(rightWheel, leftWheel);
    state->execute(rightWheel, leftWheel);
    state->exit(rightWheel, leftWheel);

    int count = 5;
    for (int i = 0; i < count; i++) {
        Serial.print("Adding Gas ");
        Serial.println(i);
        delay(1000);
        state->execute(rightWheel, leftWheel);
    }

    state = TurnRightGasing::getInstance();

    state->enter(rightWheel, leftWheel);
    state->execute(rightWheel, leftWheel);
    state->exit(rightWheel, leftWheel);

    Serial.println("Test Complete");
}

void testMotorEngine(Wheel* leftWheel, Wheel* rightWheel) {
    Serial.println("Testing Motor Engine");
    
    stayStill(leftWheel, rightWheel);

    delay(5000);

    gasToMaximumAndBreakUntilStop(leftWheel, rightWheel);

    delay(5000);

    testGasingTurningRight(leftWheel, rightWheel);

    stayStill(leftWheel, rightWheel);

    Serial.println("Motor Engine Test Complete");

    delay(1000 * 60);
    
}

#endif