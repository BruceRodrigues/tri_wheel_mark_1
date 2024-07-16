#include "input/controller.h"
#include "pins.h"
#include <Arduino.h>
#include <DigitalIO.h>
#include <PsxControllerBitBang.h>
#include <avr/pgmspace.h>
#include "config.h"

typedef const __FlashStringHelper * FlashStr;
typedef const byte* PGM_BYTES_P;
#define PSTR_TO_F(s) reinterpret_cast<const __FlashStringHelper *>(s)

using namespace Input;

const byte PIN_BUTTONPRESS = A0;
const byte PIN_HAVECONTROLLER = A1;

const char buttonSelectName[] PROGMEM = "Select";
const char buttonL3Name[] PROGMEM = "L3";
const char buttonR3Name[] PROGMEM = "R3";
const char buttonStartName[] PROGMEM = "Start";
const char buttonUpName[] PROGMEM = "Up";
const char buttonRightName[] PROGMEM = "Right";
const char buttonDownName[] PROGMEM = "Down";
const char buttonLeftName[] PROGMEM = "Left";
const char buttonL2Name[] PROGMEM = "L2";
const char buttonR2Name[] PROGMEM = "R2";
const char buttonL1Name[] PROGMEM = "L1";
const char buttonR1Name[] PROGMEM = "R1";
const char buttonTriangleName[] PROGMEM = "Triangle";
const char buttonCircleName[] PROGMEM = "Circle";
const char buttonCrossName[] PROGMEM = "Cross";
const char buttonSquareName[] PROGMEM = "Square";

const char* const psxButtonNames[PSX_BUTTONS_NO] PROGMEM = {
	buttonSelectName,
	buttonL3Name,
	buttonR3Name,
	buttonStartName,
	buttonUpName,
	buttonRightName,
	buttonDownName,
	buttonLeftName,
	buttonL2Name,
	buttonR2Name,
	buttonL1Name,
	buttonR1Name,
	buttonTriangleName,
	buttonCircleName,
	buttonCrossName,
	buttonSquareName
};

byte psxButtonToIndex(PsxButtons psxButtons) {
	byte i;

	for(i = 0; i < PSX_BUTTONS_NO; ++i) {
		if(psxButtons & 0x01) {
			break;
		}

		psxButtons >>= 1U;
	}

	return i;
}

void dumpButtons(PsxButtons psxButtons) {
	static PsxButtons lastB = 0;

	if(psxButtons != lastB) {
		lastB = psxButtons;     // Save it before we alter it
		
		Serial.print(F("Pressed: "));

		for(byte i = 0; i < PSX_BUTTONS_NO; ++i) {
			byte b = psxButtonToIndex(psxButtons);
			if(b < PSX_BUTTONS_NO) {
				PGM_BYTES_P bName = reinterpret_cast<PGM_BYTES_P>(pgm_read_ptr(&(psxButtonNames[b])));
				Serial.print(PSTR_TO_F(bName));
			}

			psxButtons &= ~(1 << b);

			if(psxButtons != 0) {
				Serial.print(F(", "));
			}
		}

		Serial.println();
	}
}

const char ctrlTypeUnknown[] PROGMEM = "Unknown";
const char ctrlTypeDualShock[] PROGMEM = "Dual Shock";
const char ctrlTypeDsWireless[] PROGMEM = "Dual Shock Wireless";
const char ctrlTypeGuitHero[] PROGMEM = "Guitar Hero";
const char ctrlTypeOutOfBounds[] PROGMEM = "(Out of bounds)";

const char* const controllerTypeStrings[PSCTRL_MAX + 1] PROGMEM = {
	ctrlTypeUnknown,
	ctrlTypeDualShock,
	ctrlTypeDsWireless,
	ctrlTypeGuitHero,
	ctrlTypeOutOfBounds
};


PsxControllerBitBang<PIN_CONTROLLER_ATT, PIN_CONTROLLER_CMD, PIN_CONTROLLER_DATA, PIN_CONTROLLER_CLOCK> psx;

boolean haveController = false;

Controller::Controller(JoyChangedCallback onRightJoyChanged, JoyChangedCallback onLeftJoyChanged, ButtonPressedCallback onButtonPressed) {
    this->onRightJoyChanged = onRightJoyChanged;
    this->onLeftJoyChanged = onLeftJoyChanged;
    this->onButtonPressed = onButtonPressed;
}

void Controller::setup() {
    fastPinMode(PIN_BUTTONPRESS, OUTPUT);
	fastPinMode(PIN_HAVECONTROLLER, OUTPUT);
	delay(300);
}

void Controller::read() {
    static byte slx, sly, srx, sry;
	
	fastDigitalWrite(PIN_HAVECONTROLLER, haveController);
	
	if(!haveController) {
		if(psx.begin()) {
            psx.setRumble(false);
			Serial.println(F("Controller found!"));
			delay(300);
			if(!psx.enterConfigMode()) {
				Serial.println(F("Cannot enter config mode"));
			} else {
				PsxControllerType ctype = psx.getControllerType();
				PGM_BYTES_P cname = reinterpret_cast<PGM_BYTES_P>(pgm_read_ptr(&(controllerTypeStrings[ctype < PSCTRL_MAX ? static_cast<byte>(ctype) : PSCTRL_MAX])));
				Serial.print(F("Controller Type is: "));
				Serial.println(PSTR_TO_F(cname));

				if(!psx.enableAnalogSticks()) {
					Serial.println(F("Cannot enable analog sticks"));
				}
				
				if(!psx.enableAnalogButtons()) {
					Serial.println(F("Cannot enable analog buttons"));
				}
				
				if(!psx.exitConfigMode()) {
					Serial.println(F("Cannot exit config mode"));
				}
			}
			
			haveController = true;
		}
	} else {
		if(!psx.read()) {
			Serial.println(F("Controller lost :("));
			haveController = false;
		} else {
			fastDigitalWrite(PIN_BUTTONPRESS, !!psx.getButtonWord());
			dumpButtons(psx.getButtonWord());

			byte lx, ly, rx, ry;
			psx.getLeftAnalog(lx, ly);
			psx.getRightAnalog(rx, ry);
			
			if(lx != slx || ly != sly) {
				if (DEBUG) {
					Serial.print("JoyLeftX: ");
					Serial.print(lx);
					Serial.print(" JoyLeftY: ");
					Serial.println(ly);
				}
				slx = lx;
				sly = ly;
                this->onLeftJoyChanged(lx, ly);
			}

			if(rx != srx || ry != sry) {
				if (DEBUG) {
					Serial.print("JoyRightX: ");
					Serial.print(rx);
					Serial.print(" JoyRightY: ");
					Serial.println(ry);
				}
				srx = rx;
				sry = ry;
                this->onRightJoyChanged(rx, ry);
			}
		}
	}

	
	delay(1000 / 60);
}