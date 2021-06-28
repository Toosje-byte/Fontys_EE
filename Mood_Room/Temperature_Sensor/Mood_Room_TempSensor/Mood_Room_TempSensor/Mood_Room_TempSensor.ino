/*
 Name:		Mood_Room_TempSensor.ino
 Created:	12/April/2021 9:08:50 PM
 Updated:   22/June/2021 
 Author:	Thomas van der Zanden
*/

//includes
#include "debounce2.h"
#include "calculateAvgTemp.h"
#include "readTempSensor.h"
#include "debounce.h"


// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;    // the number of the pushbutton pin
const int ledPin1 = 13;      // the number of the first button LED pin
const int buttonPin2 = 3;    // the number of the pushbutton pin
const int ledPin2 = 12;      // the number of the second button LED pin

const int redLed = 5;        // the number of the heater LED pin
const int blueLed = 6;       // the number of the cooler LED pin
const int tempPin = A1;      // the number of the analog sensor pin

const int tTemp1 = 5;        // the first target temperature
const int tTemp2 = 40;       // the second target temperature



//tempsensor variables
double tempArray[10] = { 21.0, 21.0, 21.0, 21.0, 21.0, 21.0, 21.0, 21.0, 21.0, 21.0 };
int tTemp = 0;  // initial target temperature

// initializing global variables
//int index = 0;
unsigned long lastChangeTime;
bool tTempSet = false;

void setup() {
    //set the inputs and outputs
    pinMode(buttonPin1, INPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(buttonPin2, INPUT);
    pinMode(ledPin2, OUTPUT);

    pinMode(blueLed, OUTPUT);
    pinMode(redLed, OUTPUT);

    //set initial LED state
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);

}



void loop() {

    //set target temperature
    if (debounce(buttonPin1))
    {
        //turn on the LED indicator
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin1, HIGH);

        //set target Temp
        tTemp = tTemp1;
        tTempSet = true;
    }
    else if (debounce(buttonPin2))
    {
        //turn on the LED indicator
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);

        //set target Temp
        tTemp = tTemp1;
        tTempSet = true;
    }

    //check if target temperature is set
    if (tTempSet) {

        //check if it has been a set interval since the last change happened
        if (millis() - lastChangeTime > 5000) {

            //read temperature sensor
            readTempSensor(tempArray, tempPin);

            //turn on the heater or cooler based on the average temperature
            if (calculateAvgTemp(tempArray) > tTemp)
            {
                //turn on the cooler indicator LED
                digitalWrite(blueLed, HIGH);
                digitalWrite(redLed, LOW);
            }
            else
            {
                //turn on the heater indicator LED
                digitalWrite(redLed, HIGH);
                digitalWrite(blueLed, LOW);
            }

             //reset the time since the last change
             lastChangeTime = millis();
        }

    }
}
