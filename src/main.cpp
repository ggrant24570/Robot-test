#include <Arduino.h>
//#include <PIDLoop.h>
#include <Pixy2.h>
//#include <Pixy2CCC.h>
//#include <Pixy2I2C.h>
//#include <Pixy2Line.h>
//#include <Pixy2SPI_SS.h>
//#include <Pixy2UART.h>
//#include <Pixy2Video.h>
//#include <TPixy2.h>
//#include <ZumoBuzzer.h>
//#include <ZumoMotors.h>
//#include <Adafruit_I2CDevice.h>
#include <Adafruit_MotorShield.h>
#include "Adafruit_VL53L0X.h"
#include "setup.h"

 

//M3 left motor
//M4 right motor
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header


// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Setting up motor ports, motor port 3 and 4
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);

// Creating pixy object
Pixy2 pixy;

// Creating sensor objects
Adafruit_VL53L0X frontSensor = Adafruit_VL53L0X();
Adafruit_VL53L0X rightFrontSensor = Adafruit_VL53L0X();
Adafruit_VL53L0X rightBackSensor = Adafruit_VL53L0X();
Adafruit_VL53L0X backSensor = Adafruit_VL53L0X();

// Holds sensor measurements
VL53L0X_RangingMeasurementData_t measure_front;
VL53L0X_RangingMeasurementData_t measure_rightFront;
VL53L0X_RangingMeasurementData_t measure_rightBack;
VL53L0X_RangingMeasurementData_t measure_back;



void setup() 
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  pixy.init();

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  // Set the speed to start, from 0 (off) to 255 (max speed)
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(0);
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  // turn on motor
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);

  // call sensor setup function:
  // pinMode, resets sensors, asigns addresses
  sensor_setup();
  

}


void loop()
{

}


