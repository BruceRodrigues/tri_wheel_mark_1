#include "input/controller.h"
#include "pins.h"
#include <Arduino.h>

using namespace Input;

Controller::Controller(JoyChangedCallback onRightJoyChanged, JoyChangedCallback onLeftJoyChanged, ButtonPressedCallback onButtonPressed) {
    this->onRightJoyChanged = onRightJoyChanged;
    this->onLeftJoyChanged = onLeftJoyChanged;
    this->onButtonPressed = onButtonPressed;
}

void Controller::setup() {
    this->psx.setupPins(PIN_CONTROLLER_DATA, PIN_CONTROLLER_CMD, PIN_CONTROLLER_ATT, PIN_CONTROLLER_CLOCK, 10);
    this->psx.config(PSXMODE_ANALOG);
}

void Controller::read() {
    this->error = psx.read(this->data);

    if (this->error == PSXERROR_SUCCESS) {
        this->onRightJoyChanged(this->data.JoyRightX, this->data.JoyRightY);
        this->onLeftJoyChanged(this->data.JoyLeftX, this->data.JoyLeftY);

        if (this->data.buttons & PSXBTN_LEFT) {
            this->onButtonPressed(PSXBTN_LEFT);
        }
        if (this->data.buttons & PSXBTN_DOWN) {
            this->onButtonPressed(PSXBTN_DOWN);
        }
        if (this->data.buttons & PSXBTN_RIGHT) {
            this->onButtonPressed(PSXBTN_RIGHT);
        }
        if (this->data.buttons & PSXBTN_UP) {
            this->onButtonPressed(PSXBTN_UP);
        }
        if (this->data.buttons & PSXBTN_START) {
            this->onButtonPressed(PSXBTN_START);
        }
        if (this->data.buttons & PSXBTN_SELECT) {
            this->onButtonPressed(PSXBTN_SELECT);
        }
        if (this->data.buttons & PSXBTN_SQUARE) {
            this->onButtonPressed(PSXBTN_SQUARE);
        }
        if (this->data.buttons & PSXBTN_CROSS) {
            this->onButtonPressed(PSXBTN_CROSS);
        }
        if (this->data.buttons & PSXBTN_CIRCLE) {
            this->onButtonPressed(PSXBTN_CIRCLE);
        }
        if (this->data.buttons & PSXBTN_TRIANGLE) {
            this->onButtonPressed(PSXBTN_TRIANGLE);
        }
        if (this->data.buttons & PSXBTN_R1) {
            this->onButtonPressed(PSXBTN_R1);
        }
        if (this->data.buttons & PSXBTN_L1) {
            this->onButtonPressed(PSXBTN_L1);
        }
        if (this->data.buttons & PSXBTN_R2) {
            this->onButtonPressed(PSXBTN_R2);
        }
        if (this->data.buttons & PSXBTN_L2) {
            this->onButtonPressed(PSXBTN_L2);
        }

    } else {
        Serial.print("No success reading data. Check connections and timing.");
    }

    delay(100);
}