#include <Arduino.h>
#include "HX711.h"
#include "Scale.h"
#include "RGBLed.h"
#include "PnuematicActuator.h"
#include "DispenserController.h"

// Scale Data
const int loadCellDT = 18;
const int loadCellSCK = 19;
HX711 scale;
const float scale0_offset = 666.06;
Scale scale0(&scale, loadCellDT, loadCellSCK, scale0_offset);

// RGBLed Data
const int redPin = 21;
const int greenPin = 5;
RGBLed indicatorLed(redPin, greenPin);

// Pnuematic Actuator Data
const int relayPin = 23;
PnuematicActuator piston(relayPin);

// Dispensor Data
DispenserController controller(&scale0, &indicatorLed, &piston);

void setup() {
	// Serial Init
	Serial.begin(115200);
	while (!Serial) { 
        delay(10); 
    }
	delay(1000);

	Serial.println("Scale initilization");
	scale0.begin();
	scale0.initalizeScale();
	Serial.println("Initilaztion Complete!");
}

void loop() {
	controller.update();
}