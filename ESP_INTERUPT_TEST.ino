#include <Arduino.h>



// ==================== TUNEABLE PARAMETERS ====================

// Uncomment these lines in order to activate Serial debug
#define DEBUG
#define DEBUGLIB_BAUDS 115200

// Button is used to permit MAC or enter WEB server mode
#define BUTTON_PIN D6

// button press durations:
// regular: Add last MAC
// long: Go AP Server mode (creates its own WiFi)
#define PIN_LONG_PRESS_MS 1000

volatile bool lastPinStatus = true;
volatile bool pinStatus = true;
volatile unsigned long pinLastTrigger = 0;
volatile bool shortPress = false;
volatile bool longPress = false;


// ==================== Function definitions ====================
void setup();
void loop();
void pinInterrupt();


// ==================== Debug functionality; simplified, taken from: https://github.com/Naguissa/uDebugLib ====================
#ifdef DEBUG
	#define uDebugLibInit() Serial.begin(DEBUGLIB_BAUDS)
	#define DEBUG_PRINT Serial.print
	#define DEBUG_PRINTLN Serial.println
#else
	#define uDebugLibInit()
	#define DEBUG_PRINT
	#define DEBUG_PRINTLN
#endif



// ==================== Setup functions ====================


// This section of code runs only once at start-up.
void setup() {
	uDebugLibInit();
	DEBUG_PRINTLN("Serial OK (if debug enabled)");

	pinMode(BUTTON_PIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), pinInterrupt, CHANGE);
}



//
// ==================== LOOP ====================
//

void loop() {
	if (lastPinStatus != pinStatus) {
		lastPinStatus = pinStatus;
		DEBUG_PRINT("Pin status changed; new status: ");
		DEBUG_PRINTLN(pinStatus ? "ON" : "OFF");
	}

	if (shortPress) {
		shortPress = false;
		DEBUG_PRINTLN("Short press detected");
	}
	if (longPress) {
		longPress = false;
		DEBUG_PRINTLN("Long press detected");
	}

}



// ==================== PIN CHANGE INTERRUPT ====================

ICACHE_RAM_ATTR void pinInterrupt() {
	bool prev = pinStatus;
	pinStatus = digitalRead(BUTTON_PIN);

	if (prev == pinStatus) {
		return;  // Skip, duplicate
	}
	if (pinStatus) { // Pressed
		pinLastTrigger = millis();
	} else { // release
		if (pinLastTrigger == 0) {
			return; // Release without press? Any failure
		}
		if (millis() > pinLastTrigger + PIN_LONG_PRESS_MS) { //  Long press
			longPress = true;
		} else { // Short press
			shortPress = true;
		}
		pinLastTrigger = 0;
	}
}
