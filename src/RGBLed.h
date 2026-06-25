/*
*   Class Responsibility
*   Provide visual feedback to user via turning on LED
*/

#ifndef RGB_LED_H
#define RGB_LED_H

#include <Arduino.h>

class RGBLed {
    private:
        int redPin;
        int greenPin;

    public:
        bool status;
        RGBLed(int redPin, int greenPin);
        void begin();
        void idleStatus();
        void activeStatus();
};

#endif