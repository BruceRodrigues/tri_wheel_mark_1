#include "engine/motorEngine.h"
#include "pins.h"
#include "config.h"
#include "engine/stateMachine/state.h"
#include "engine/stateMachine/engineStates.h"
#include "engine/wheel.h"
#include "engine/motorEngineTest.h"

using namespace Engine;

MotorEngine::MotorEngine() {
    this->leftWheel = new Wheel(PIN_WHEEL_LEFT_FORWARD, PIN_WHEEL_LEFT_BACKWARD, PIN_WHEEL_LEFT_PWM);
    this->rightWheel = new Wheel(PIN_WHEEL_RIGHT_FORWARD, PIN_WHEEL_RIGHT_BACKWARD, PIN_WHEEL_RIGHT_PWM);
    this->currentState = Idle::getInstance();
}

void MotorEngine::setup() {
    this->leftWheel->setup();
    this->rightWheel->setup();
}

void MotorEngine::update() {
    if (TEST_MODE) {
        testMotorEngine(this->leftWheel, this->rightWheel);
        return;
    }

    this->currentState->execute(this->rightWheel, this->leftWheel);
}

void MotorEngine::transitionTo(State* newState) {
    this->currentState->exit(this->rightWheel, this->leftWheel);
    this->currentState = newState;
    this->currentState->enter(this->rightWheel, this->leftWheel);
}