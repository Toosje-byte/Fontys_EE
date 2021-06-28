// 
// 
// 

#include "readTempSensor.h"


int index = 0;

double readTempSensor(double* tempArray, int tempPin)
{
    //read temperature sensor
    int inputTemp = analogRead(tempPin);

    double a = 0.9527032322;
    double n = ((250.0 / (inputTemp * 0.0049)) - 50.0) / 39.46268791;

    //Get temp
    double currentTemp = log(n) / log(a);

    //write temperature into array
    tempArray[index] = currentTemp;

    index += 1;

    //reset index when the end of the array is reached
    if (index >= 10)
    {
        index = 0;
    }

}
