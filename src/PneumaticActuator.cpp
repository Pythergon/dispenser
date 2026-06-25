/*
*   Class Responsibility
*   Toggle the relay pin for the piston
*/

#include "PneumaticActuator.h"

PneumaticActuator::PneumaticActuator(int relayPin) {
    this->relayPin = relayPin;
}

void PneumaticActuator::begin() {
    // Preset the latch HIGH (retracted) before enabling output so the
    // relay never glitches into the extended state at startup.
    digitalWrite(this->relayPin, HIGH);
    pinMode(this->relayPin, OUTPUT);
    digitalWrite(this->relayPin, HIGH);
    this->status = false;
}

void PneumaticActuator::extend() {
    this->status = true;
    digitalWrite(this->relayPin, LOW);
}

void PneumaticActuator::retract() {
    this->status = false;
    digitalWrite(this->relayPin, HIGH);
}
