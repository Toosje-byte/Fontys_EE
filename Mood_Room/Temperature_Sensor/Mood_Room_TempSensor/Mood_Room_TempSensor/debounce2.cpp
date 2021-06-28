// 
// 
// 

#include "debounce2.h"


int buttonState = LOW;					// the current reading from the input pin
int lastButtonState = LOW;				// the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;		// the last time the output pin was toggled


// Function for debouncing a button input
// Parameters:
//		buttonPin	the pin to which the button is connected
// Returns HIGH once if the button is pressed, LOW otherwise
int debounce(int buttonPin)
{
	int result = LOW;	// value to be returned after executing the function

	// read the state of the switch into a local variable:
	int reading = digitalRead(buttonPin);

	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH),  and you've waited
	// long enough since the last press to ignore any noise:

	// if the switch changed, due to noise or pressing:
	if (reading != lastButtonState)
	{
		// reset the debouncing timer
		lastDebounceTime = millis();
	}

	if ((millis() - lastDebounceTime) > debounceDelay)
	{
		// whatever the reading is at, it's been there for longer than
		// the debounce delay, so take it as the actual current state:

		// if the button state has changed:
		if (reading != buttonState)
		{
			buttonState = reading;

			// only toggle the LED if the new button state is HIGH
			if (buttonState == HIGH)
			{
				result = HIGH;
			}
		}
	}

	// save the reading.  Next time through the function,
	// it'll be the lastButtonState:
	lastButtonState = reading;

	return result;
}