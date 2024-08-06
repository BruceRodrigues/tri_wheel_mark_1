#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>

typedef void (*JoyChangedCallback)(int, int);
typedef void (*ButtonPressedCallback)(uint16_t);

namespace Input {

    class Controller {

    public:
        Controller(JoyChangedCallback onRightJoyChanged, JoyChangedCallback onLeftJoyChanged, ButtonPressedCallback onButtonPressed);
        void setup();
        void read();

    private:
        JoyChangedCallback onRightJoyChanged;
        JoyChangedCallback onLeftJoyChanged;
        ButtonPressedCallback onButtonPressed;

    };

}

#endif