/*
*   Class Responsibility
*   Initialize and Read Sensor Data
*/

#ifndef SCALE_H
#define SCALE_H

#include <Arduino.h>
#include <HX711.h>

class Scale {
    private:
        int DTPin;
		int SCKPin;
		HX711* scale;
		float calibrationFactor;

    public:
        float sensorData;
        Scale(HX711* scale, int DTPin, int SCKPin, float calibrationFactor);
        void begin();
        void initializeScale();
        void tare();
        void readData(int dt = 100);
};

#endif