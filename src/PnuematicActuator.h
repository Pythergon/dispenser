/*
*   Class Responsibility
*   Toggle the relay pin for the piston
*/

#ifndef PNUEMATIC_ACTUATOR_H
#define PNUEMATIC_ACTUATOR_H

#include <Arduino.h>

class PnuematicActuator {
    private:
        int relayPin;

    public:
        bool status;
        PnuematicActuator(int relayPin);
        void extend();
        void retract();
};

#endif