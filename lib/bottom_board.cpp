#include "bottom_board.h"
#include <Adafruit_MotorShield.h>
#include <Pixy2.h>

Navigation::Navigation()
{   // ^constructor!
    

}


void Navigation::line_follow(int default_speed, int exit_mode, int number)
{   // assuming these are instantiated in main and that we don't have to pass them in
    // Adafruit_DCMotor *leftMotor = AFMS.getMotor(3); // right
    // Adafruit_DCMotor *rightMotor = AFMS.getMotor(4); // left
    uint8_t i;
    //pixy.ccc.getBlocks();
    int xcenter;
    bool exit = false;

    /* if (exit_mode == encoder){
        int rotation_cap = encoder_conversion(number);
    }*/

    // TEST
    while (exit == false) {
        pixy.ccc.getBlocks();
        if (pixy.ccc.numBlocks)
        {
            xcenter = pixy.ccc.blocks[0].m_x;
            if (xcenter < 128){
                // if robot is veering right, make right go faster, left go slower
                leftMotor->run(FORWARD);
                leftMotor->setSpeed(default_speed+30);
                rightMotor->run(FORWARD);
                rightMotor->setSpeed(default_speed-30);
            } else if (xcenter > 128){
                // if robot is veering left, make left go faster, right go slower
                leftMotor->run(FORWARD);
                leftMotor->setSpeed(default_speed-30);
                rightMotor->run(FORWARD);
                rightMotor->setSpeed(default_speed+30);
            } else if (xcenter == 128){
                leftMotor->run(FORWARD);
                leftMotor->setSpeed(default_speed);
                rightMotor->run(FORWARD);
                rightMotor->setSpeed(default_speed);
            }
            
        } else {
            // if no line detected, motors no go
            leftMotor->run(RELEASE);
            rightMotor->run(RELEASE);
            leftMotor->setSpeed(0);
            rightMotor->setSpeed(0);
        }

        if (exit_mode == distance){
            frontSensor.rangingTest(&measure_front,false); // take measurement (front sensor)
            if ((measure_front.RangeMilliMeter > number*inchToMilli) || (measure_front.RangeStatus = 4)){
                // if farther than we want to be using front sensor or if detect "out of range"
                exit = false;
            } else if (measure_front.RangeMilliMeter <= number*inchToMilli) {
                // if we are equal to or closer than distance specified
                exit = true;
                // stop motors; this could go outside big loop
                leftMotor->run(RELEASE);
                rightMotor->run(RELEASE);
                leftMotor->setSpeed(0);
                rightMotor->setSpeed(0);
            }
        }

        /* may not use this, maybe interrupts
        if (exit_mode == encoder){
            // somehow have to keep track of encoder rotations
            // actually do not know how we are going to do that
            // have to figure out how the encoders work first
            if (encoder_count >= rotation_cap){
                // if encoder rotations is equal or over the set rotations wanted, stop
                exit = true;
                // stop motors; this could go outside big loop
                leftMotor->run(RELEASE);
                rightMotor->run(RELEASE);
                leftMotor->setSpeed(0);
                rightMotor->setSpeed(0);
            } else if (encoder_count < rotation_cap){
                // if encoder rotations is less than set rotations wanted, keep going
                exit = false;
            }
        }*/

    }
    
}

void Navigation::pivot90(int direction)
{   // this will be done off of encoder rotations
    int encoder_count_left = 0;
    int encoder_count_right = 0;

}

void Navigation::pivot45(int direction)
{   // this will be done off of encoder rotations
    int encoder_count_left = 0;
    int encoder_count_right = 0;

}

void Navigation::move_encoder(int inches)
{
    int encoder_count_left = 0;
    int encoder_count_right = 0;
}

void Navigation::move_sensor(int wall_dist, int sensor)
{   // move forward until sensor distance wanted
    int default_speed = 140;
    bool move = true;

    if (sensor == frontSensor) {   
        while (move == true){
            leftMotor->run(FORWARD);
            leftMotor->setSpeed(default_speed);
            rightMotor->run(FORWARD);
            rightMotor->setSpeed(default_speed);
            frontSensor.rangingTest(&measure_front, false); // take measurement (front sensor)
            if (measure_front.RangeMilliMeter <= wall_dist*inchToMilli) {
                // if we are equal to or closer than distance specified
                move = false;
                // stop motors; this could go outside while loop
                leftMotor->run(RELEASE);
                rightMotor->run(RELEASE);
                leftMotor->setSpeed(0);
                rightMotor->setSpeed(0);
            }
        }
    } else if (sensor == backSensor) {
        while (move == true){
            leftMotor->run(BACKWARD);
            leftMotor->setSpeed(default_speed);
            rightMotor->run(BACKWARD);
            rightMotor->setSpeed(default_speed);
            backSensor.rangingTest(&measure_back, false); // take measurement (back sensor)
            if (measure_back.RangeMilliMeter <= wall_dist*inchToMilli) {
                // if we are equal to or closer than distance specified
                move = false;
                // stop motors; this could go outside while loop
                leftMotor->run(RELEASE);
                rightMotor->run(RELEASE);
                leftMotor->setSpeed(0);
                rightMotor->setSpeed(0);
            }
        }
    }
}

WallFollow::WallFollow()
{   // ^constructor

}

void WallFollow::square_up()
{

}

void WallFollow::follow_wall(int inches, int direction)
{

}


void WallFollow::open(int wall_dist, int direction)
{

}

void WallFollow::close(int wall_dist, int direction)
{

}

