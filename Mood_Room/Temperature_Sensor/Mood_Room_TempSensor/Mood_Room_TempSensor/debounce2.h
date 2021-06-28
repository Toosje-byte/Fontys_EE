// debounce2.h

#ifndef _DEBOUNCE2_h
#define _DEBOUNCE2_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
const unsigned long debounceDelay = 50;		// the debounce time; increase if the output flickers


// Function for debouncing a button input
// Parameters:
//		buttonPin	the pin to which the button is connected
// Returns HIGH once if the button is pressed, LOW otherwise
int debounce(int buttonPin);

#endif

