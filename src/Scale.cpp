/*
*   Class Responsibility
*   Initialize and Read Sensor Data
*/

#include "Scale.h"

Scale::Scale(HX711* scale, int DTPin, int SCKPin, float calibrationFactor) {
    this->scale = scale;
    this->DTPin = DTPin;
    this->SCKPin = SCKPin;
    this->calibrationFactor = calibrationFactor;
    this->sensorData = 0;
}

void Scale::begin() {
    this->scale->begin(this->DTPin, this->SCKPin);
}

void Scale::initializeScale() {
    while (!this->scale->is_ready()) {
        delay(1000);
    }

    this->scale->read();
    this->scale->set_scale(this->calibrationFactor);
    this->scale->tare();
}

void Scale::tare() {
    this->scale->tare();
}

void Scale::readData(int dt) {
    delay(dt);
    this->sensorData = this->scale->get_units();
}
