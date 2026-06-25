/*
*   Class Responsibilty
*   Orchestrate the dispenser parts
*/

#ifndef DISPENSER_CONTROLLER_H
#define DISPENSER_CONTROLLER_H

#include <Arduino.h>
#include "Scale.h"
#include "RGBLed.h"
#include "PnuematicActuator.h"

class DispenserController {
    private:
        Scale* scale;
        RGBLed* rgbLed;
        PnuematicActuator* pnuematicActuator;

    public:
        DispenserController(Scale* scale, RGBLed* rgbLed, PnuematicActuator* PnuematicActuator);
        void update();
};

#endif