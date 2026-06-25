/*
*   Class Responsibility
*   Orchestrate the dispenser parts
*/

#ifndef DISPENSER_CONTROLLER_H
#define DISPENSER_CONTROLLER_H

#include <Arduino.h>
#include "Scale.h"
#include "RGBLed.h"
#include "PneumaticActuator.h"

class DispenserController {
    private:
        Scale* scale;
        RGBLed* rgbLed;
        PneumaticActuator* pneumaticActuator;

        // Weight (in scale units) above which a dispense cycle is triggered.
        static const int dispenseThreshold = 10;
        // How long the piston stays extended per dispense cycle, in ms.
        static const int dispenseHoldMs = 150;

    public:
        DispenserController(Scale* scale, RGBLed* rgbLed, PneumaticActuator* pneumaticActuator);
        void update();
};

#endif