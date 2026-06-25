/*
*   Class Responsibility
*   Toggle the relay pin for the piston
*/

#include "PnuematicActuator.h"

PnuematicActuator::PnuematicActuator(int relayPin) {
    this->relayPin = relayPin;
    pinMode(relayPin, OUTPUT);
}

void PnuematicActuator::extend(){
    this->relayPin = relayPin;
    digitalWrite(relayPin, LOW);
}

void PnuematicActuator::retract() {
    this->status = false;
    digitalWrite(this->relayPin, HIGH);
}