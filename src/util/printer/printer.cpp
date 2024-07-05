#include "printer.h"
#include <Arduino.h>

using namespace Util;

static bool initialized;

void Printer::println(const char* message) {
    Serial.println(message);
}

void Printer::print(const char* message) {
    Serial.print(message);
}