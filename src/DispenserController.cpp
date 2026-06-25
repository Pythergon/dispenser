/*
*   Class Responsibility
*   Orchestrate the dispenser parts
*/

#include "DispenserController.h"

DispenserController::DispenserController(Scale* scale, RGBLed* rgbLed, PneumaticActuator* pneumaticActuator) {
    this->scale = scale;
    this->rgbLed = rgbLed;
    this->pneumaticActuator = pneumaticActuator;
}

void DispenserController::update() {
    this->scale->readData();

    if (this->scale->sensorData > dispenseThreshold) {
        this->pneumaticActuator->extend();
        this->rgbLed->activeStatus();
        delay(dispenseHoldMs);
        this->scale->tare();
    } else {
        this->rgbLed->idleStatus();
        this->pneumaticActuator->retract();
    }
}
