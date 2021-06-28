// readTempSensor.h

#ifndef _READTEMPSENSOR_h
#define _READTEMPSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// Function for reading the temperature sensor, and writing it into tempArray
// Parameters:
//		none
// returns none
double readTempSensor(double* tempArray, int tempPin);

#endif

