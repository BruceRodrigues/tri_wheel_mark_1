#ifndef CONTROLLER_H
#define CONTROLLER_H

typedef void (*JoyChangedCallback)(int, int);
typedef void (*ButtonPressedCallback)(int);

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