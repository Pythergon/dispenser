/*
*   Class Responsibility
*   Toggle the relay pin for the piston
*/

#ifndef PNEUMATIC_ACTUATOR_H
#define PNEUMATIC_ACTUATOR_H

#include <Arduino.h>

class PneumaticActuator {
    private:
        int relayPin;

    public:
        bool status;
        PneumaticActuator(int relayPin);
        void begin();
        void extend();
        void retract();
};

#endif
