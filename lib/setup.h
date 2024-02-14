#include <Arduino.h>
#include "pins_bottom_board.h"

// setup functions for all the different components

void sensor_setup(){
    // Pin Setup
    pinMode(XSHUT1, OUTPUT);
    pinMode(XSHUT2, OUTPUT);
    pinMode(XSHUT3, OUTPUT);
    pinMode(XSHUT4, OUTPUT);

    // Distance Sensor Setup
    // Reset Sensor
    digitalWrite(XSHUT1, LOW);
    digitalWrite(XSHUT2, LOW);
    digitalWrite(XSHUT3, LOW);
    digitalWrite(XSHUT4, LOW);
    delay(10);
    digitalWrite(XSHUT1, HIGH);
    digitalWrite(XSHUT2, HIGH);
    digitalWrite(XSHUT3, HIGH);
    digitalWrite(XSHUT4, HIGH);

    // Set Sensor I2C Addresses one-by-one
    digitalWrite(XSHUT2, HIGH);
    digitalWrite(XSHUT3, HIGH);
    digitalWrite(XSHUT4, HIGH);
    frontSensor.begin(0x30);
    digitalWrite(XSHUT2, HIGH);
    rightFrontSensor.begin(0x31);
    digitalWrite(XSHUT3, HIGH);
    rightBackSensor.begin(0x32);
    digitalWrite(XSHUT4, HIGH);
    backSensor.begin(0x33);
    
}