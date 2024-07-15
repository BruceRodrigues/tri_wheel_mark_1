#include "wheel.h"
#include <Arduino.h>
#include "config.h"

using namespace Engine;

const int MAX_SPEED = 255;
const int MIN_SPEED = 0;
const int SPEED_STEP = 10;

Wheel::Wheel(int forwardPin, int backwardPin, int pwmPin) {
    this->forwardPin = forwardPin;
    this->backwardPin = backwardPin;
    this->pwmPin = pwmPin;
}

void Wheel::setup() {
    pinMode(this->forwardPin, OUTPUT);
    pinMode(this->backwardPin, OUTPUT);
    pinMode(this->pwmPin, OUTPUT);
}

void Wheel::forward() {
    digitalWrite(this->forwardPin, HIGH);
    digitalWrite(this->backwardPin, LOW);
}

void Wheel::backward() {
    digitalWrite(this->forwardPin, LOW);
    digitalWrite(this->backwardPin, HIGH);
}

void Wheel::reset() {
    digitalWrite(this->forwardPin, LOW);
    digitalWrite(this->backwardPin, LOW);
    this->speed = 0;
    analogWrite(this->pwmPin, this->speed);
}

void Wheel::gas() {
    if ( this->speed >= MAX_SPEED ) {
        return;
    }

    this->speed += SPEED_STEP;
    analogWrite(this->pwmPin, this->speed);

    if (DEBUG) {
        Serial.print("GAS - current speed: ");
        Serial.println(this->speed);
    }
}

void Wheel::breaking() {
    if ( this->speed <= MIN_SPEED ) {
        return;
    }

    this->speed -= SPEED_STEP;
    analogWrite(this->pwmPin, this->speed);

    if (DEBUG) {
        Serial.print("BREAKING - current speed: ");
        Serial.println(this->speed);
    }
}