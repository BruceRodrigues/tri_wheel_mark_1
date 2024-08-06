#ifndef PIN_H
#define PIN_H

#include <Arduino.h>

const int PIN_REMOTE_CONTROL = 12;

//MOTORS
const int PIN_WHEEL_RIGHT_FORWARD = 5;
const int PIN_WHEEL_RIGHT_BACKWARD = 7;
const int PIN_WHEEL_LEFT_FORWARD = 4;
const int PIN_WHEEL_LEFT_BACKWARD = 2;
const int PIN_WHEEL_RIGHT_PWM = 6; 
const int PIN_WHEEL_LEFT_PWM = 3;

//CONTROLS
const int PIN_CONTROLLER_DATA = 12;
const int PIN_CONTROLLER_CMD = 10;
const int PIN_CONTROLLER_ATT = 13;
const int PIN_CONTROLLER_CLOCK = 11;

//LEDS
const int PIN_LIGHT = 9;
const int PIN_RIGHT_INDICATOR_LIGHT = 8;
const int PIN_LEFT_INDICATOR_LIGHT = A0;

#endif