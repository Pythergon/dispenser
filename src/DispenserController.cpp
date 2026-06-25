/*
*   Class Responsibilty
*   Orchestrate the dispenser parts
*/

#include "DispenserController.h"

DispenserController::DispenserController(Scale* scale, RGBLed* rgbLed, PnuematicActuator* pnuematicActuator) {
    this->scale = scale;
    this->rgbLed = rgbLed;
    this->pnuematicActuator = pnuematicActuator;
}

void DispenserController::update() {
    this->scale->readData();

    if (this->scale->sensorData >10) {
        this->pnuematicActuator->extend();
        this->rgbLed->activeStatus();
        delay(150);
        this->scale->tare();
    } else {
        this->rgbLed->idleStatus();
        this->pnuematicActuator->retract();
    }
}