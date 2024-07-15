#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <PSX.h>

typedef void (*JoyChangedCallback)(int, int);
typedef void (*ButtonPressedCallback)(int);

namespace Input {

    class Controller {

    public:
        Controller(JoyChangedCallback onRightJoyChanged, JoyChangedCallback onLeftJoyChanged, ButtonPressedCallback onButtonPressed);
        void setup();
        void read();

    private:
        PSX psx;
        PSX::PSXDATA data;
        int error;
        JoyChangedCallback onRightJoyChanged;
        JoyChangedCallback onLeftJoyChanged;
        ButtonPressedCallback onButtonPressed;

    };

}

#endif