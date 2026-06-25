#include <Arduino.h>
#include "HX711.h"
#include "Scale.h"
#include "RGBLed.h"
#include "PneumaticActuator.h"
#include "DispenserController.h"

// Scale Data
const int loadCellDT = 18;
const int loadCellSCK = 19;
HX711 scale;
const float scale0_calibrationFactor = 666.06;
Scale scale0(&scale, loadCellDT, loadCellSCK, scale0_calibrationFactor);

// RGBLed Data
const int redPin = 21;
const int greenPin = 5;
RGBLed indicatorLed(redPin, greenPin);

// Pneumatic Actuator Data
const int relayPin = 23;
PneumaticActuator piston(relayPin);

// Dispenser Data
DispenserController controller(&scale0, &indicatorLed, &piston);

void setup() {
	// Serial Init
	Serial.begin(115200);
	while (!Serial) {
        delay(10);
    }
	delay(1000);

	// Drive the actuator to its safe (retracted) state first.
	piston.begin();
	indicatorLed.begin();

	Serial.println("Scale initialization");
	scale0.begin();
	scale0.initializeScale();
	Serial.println("Initialization Complete!");
}

void loop() {
	controller.update();
}
