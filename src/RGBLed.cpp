/*
*   Class Responsibility
*   Provide visual feedback to user via turning on LED
*/

#include "RGBLed.h"

RGBLed::RGBLed(int redPin, int greenPin) {
    this->redPin = redPin;
    this->greenPin = greenPin;

    pinMode(this->redPin, OUTPUT);
    pinMode(this->greenPin, OUTPUT);
}

void RGBLed::idleStatus() {
    this->status = false;
    digitalWrite(this->redPin, LOW);
    digitalWrite(this->greenPin, HIGH);
}

void RGBLed::activeStatus() {
    this->status = false;
    digitalWrite(this->redPin, HIGH);
    digitalWrite(this->greenPin, LOW);
}