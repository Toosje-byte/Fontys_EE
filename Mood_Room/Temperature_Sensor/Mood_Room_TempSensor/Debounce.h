#include "Debounce.cpp"


// Lazy debounce function copied from arduino site, i only changed how it sets the LED pin to high and added the change to target temperature
void debounce(const int& buttonPin, const int& ledPinGiven, int& ledState, int& buttonState, int& lastButtonState, unsigned long& lastDebounceTime, unsigned long& debounceDelay, int tTempGiven);
