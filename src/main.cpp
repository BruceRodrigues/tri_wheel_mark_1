#include <Arduino.h>
#include <IRremote.h>
#include "engine/wheels/wheels.h"
#include "pins.h"

using namespace Engine;

Wheels wheels;

void setup() {
    IrReceiver.begin(PIN_REMOTE_CONTROL, ENABLE_LED_FEEDBACK);
    Serial.begin(9600);
    wheels.setup();
}


void loop() {

    if (IrReceiver.decode()) {

        /*
         * Print a summary of received data
         */
        // if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            // Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
            // We have an unknown protocol here, print extended info
            // IrReceiver.printIRResultRawFormatted(&Serial, true);
            // IrReceiver.resume(); // Do it here, to preserve raw data for printing with printIRResultRawFormatted()

        // } else {
            IrReceiver.resume(); // Early enable receiving of the next IR frame
            Serial.println();
            Serial.print(F("Received: "));
            Serial.print(IrReceiver.decodedIRData.command);
            // IrReceiver.printIRResultShort(&Serial);
            // IrReceiver.printIRSendUsage(&Serial);
        // }

        if (IrReceiver.decodedIRData.command == 64) { //Number 6
            wheels.turnRight();
        } else if (IrReceiver.decodedIRData.command == 68) { //Number 8
            wheels.turnLeft();
        } else if (IrReceiver.decodedIRData.command == 21) { //Number 4
            wheels.forward();
        } else if (IrReceiver.decodedIRData.command == 7) { //Number 2
            wheels.backward();
        } else if (IrReceiver.decodedIRData.command == 67) { //Number 5
            wheels.reset();
        }


    }


}

