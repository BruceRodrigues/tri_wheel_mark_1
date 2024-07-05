#include "wheels.h"
#include "pins.h"
#include <Arduino.h>
#include "util/printer/printer.h"
#include "config.h"

using namespace Engine;

Wheels::Wheels() {
}

void Wheels::setup() {
    pinMode(PIN_MOTOR_RIGHT_FORWARD, OUTPUT);
    pinMode(PIN_MOTOR_RIGHT_BACKWARD, OUTPUT);
    pinMode(PIN_MOTOR_LEFT_FORWARD, OUTPUT);
    pinMode(PIN_MOTOR_LEFT_BACKWARD, OUTPUT);
}

void Wheels::turnRight() {
        turn(RIGHT);
}

void Wheels::turnLeft() {
        turn(LEFT);
}

void Wheels::reset() {
    digitalWrite(PIN_MOTOR_LEFT_FORWARD, LOW);
    digitalWrite(PIN_MOTOR_RIGHT_FORWARD, LOW);
    digitalWrite(PIN_MOTOR_RIGHT_BACKWARD, LOW);
    digitalWrite(PIN_MOTOR_LEFT_BACKWARD, LOW);
}

void Wheels::forward() {
    digitalWrite(PIN_MOTOR_LEFT_FORWARD, HIGH);
    digitalWrite(PIN_MOTOR_RIGHT_FORWARD, HIGH);
    digitalWrite(PIN_MOTOR_RIGHT_BACKWARD, LOW);
    digitalWrite(PIN_MOTOR_LEFT_BACKWARD, LOW);
}

void Wheels::backward() {
    digitalWrite(PIN_MOTOR_LEFT_FORWARD, LOW);
    digitalWrite(PIN_MOTOR_RIGHT_FORWARD, LOW);
    digitalWrite(PIN_MOTOR_RIGHT_BACKWARD, HIGH);
    digitalWrite(PIN_MOTOR_LEFT_BACKWARD, HIGH);
}

void Wheels::turn(Direction direction) {

    if (DEBUG) {
        Serial.print("turning ");
        Serial.println(direction);
    }

    digitalWrite(PIN_MOTOR_LEFT_FORWARD, direction == RIGHT);
    digitalWrite(PIN_MOTOR_RIGHT_FORWARD, direction != RIGHT);
    digitalWrite(PIN_MOTOR_RIGHT_BACKWARD, direction == RIGHT);
    digitalWrite(PIN_MOTOR_LEFT_BACKWARD, direction != RIGHT);
    
}


