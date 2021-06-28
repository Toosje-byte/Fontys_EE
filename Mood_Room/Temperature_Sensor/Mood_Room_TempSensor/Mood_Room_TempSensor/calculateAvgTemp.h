// calculateAvgTemp.h

#ifndef _CALCULATEAVGTEMP_h
#define _CALCULATEAVGTEMP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// Function calculating the average temperature
// Parameters:
//		none
// returns the average temperature
int calculateAvgTemp(double* tempArray);

#endif

