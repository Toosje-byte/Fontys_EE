// 
// 
// 

#include "calculateAvgTemp.h"

int calculateAvgTemp(double* tempArray)
{
    //calculate the average temperature
    double totalTemp = 0;

    for (int i = 0; i < 10; i++) {
        totalTemp += tempArray[i];
    }

    //converting to int always rounds down so i add 0,5 to make sure that it gets rounded correctly
    totalTemp += 0.5;

    int avgTemp = int(totalTemp) / 10;

    return avgTemp;
}
