/*
This file contains code to actuate movements of the robot, like drivetrain or arm actuators
*/

#include <frc/TimedRobot.h>
#include "ctre/Phoenix.h"
#include <math.h>

#pragma once

//Motor power is a value from -1 to 1. Basic implementation sets this from the joystick input, but in future it can be influenced by PID controllers for stabilizing
//See RobotMappings.txt for info on control mappings
double motorPower[4] = {0,0,0,0};

//Wheel Angles in Radians (currently replaced with motorVectorFactor due to reduced overhead)
double motorAngles[4] = {0.78539816339744830961566084581988, 2.3561944901923449288469825374596, 3.9269908169872415480783042290994, 5.4977871437821381673096259207391};

//sin(theta) where theta is wheel angle where [0][i] will be sin (Y-axis) and [1][i] will be cos (X-axis)
double motorVectorFactor[2][4];



class driveTrain {
    public:

    //This code uses the motor angles, currently set above (may be ported to .conf file in the future), to calculate the applied power factors
    void populateMotorVectorFactors() {
        for (int i = 0; i < 2; i++) {
            motorVectorFactor[0][i] = sin(motorAngles[i]);
            motorVectorFactor[1][i] = cos(motorAngles[i]);
        }
    }

    //Initialize Motor Controllers
    void initDriveTrain() {
        for (int i = 0; i < 3; i++) {
            
        }
    }

    void calculateMotorVectors() {
        for (int i = 0; i < 3; i++) {
            motorPower[i] = -1 * motorVectorFactor[0][i] * yRefinedVel - motorVectorFactor[1][i] * xRefinedVel + zRefinedRot;
        }
    }

    void setMotorPower() {
        for (int i = 0; i < 3; i++) {

        }
    }
};