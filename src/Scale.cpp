/*
*   Class Responsibilty   
*   Initalize and Read Sensor Data
*/

#include "Scale.h"

Scale::Scale(HX711* scale, int DTPin, int SCKPin, float scale_offset) {
    this->scale = scale;
    this->DTPin = DTPin;
    this->SCKPin = SCKPin;
    this->scale_offset = scale_offset;
}

void Scale::begin() {
    this->scale->begin(this->DTPin, this->SCKPin);
}

void Scale::initalizeScale() {
    while (!this->scale->is_ready()) {
        delay(1000);
    }

    this->scale->read();
    this->scale->set_scale(this->scale_offset);
    this->scale->tare();
}

void Scale::readData(int dt = 100) {
    delay(dt);
    this->sensorData = this->scale->get_units();
}