/*
This file contains code to actuate movements of the robot, like drivetrain or arm actuators
*/

#include <frc/TimedRobot.h>
#include "ctre/Phoenix.h"
#include <math.h>

/* Really good for Testing
Step 1: Enable these:
#include <sstream>
#include "frc/smartdashboard/SmartDashboard.h"

Step 2: Replace "DOUBLE_VALUE" with a mischevious double and it will print to Driver's Station
std::ostringstream strs;
strs << DOUBLE_VALUE;
std::string str = strs.str();
frc::SmartDashboard::PutString("DB/String 1", str);
*/

#pragma once



//Motor power is a value from -1 to 1. Basic implementation sets this from the joystick input, but in future it can be influenced by PID controllers for stabilizing
//See RobotMappings.txt for info on control mappings
double motorPower[4] = {0,0,0,0};

//Wheel Angles in Radians (currently replaced with motorVectorFactor due to reduced overhead)
double motorAngles[4] = {0.78539816339744830961566084581988, 2.3561944901923449288469825374596, 3.9269908169872415480783042290994, 5.4977871437821381673096259207391};

//sin(theta) where theta is wheel angle where [0][i] will be sin (Y-axis) and [1][i] will be cos (X-axis)
double motorVectorFactor[2][4];

//Create an array of objects for motor controllers
TalonSRX driveWheel[4] = {{10}, {11}, {12}, {13}};



class driveTrain {
    public:

    //This code uses the motor angles, currently set above (may be ported to .conf file in the future), to calculate the applied power factors
    virtual void populateMotorVectorFactors() {
        for (int i = 0; i < 4; i++) {
            motorVectorFactor[0][i] = sin(motorAngles[i]);
            motorVectorFactor[1][i] = cos(motorAngles[i]);
        }
    }

    //Use the values set in populateMotorVectorFactors to set the required power for each motor
    virtual void calculateDriveMotorVectors() {
        for (int i = 0; i < 4; i++) {
            motorPower[i] = -1 * motorVectorFactor[0][i] * yRefinedVel - motorVectorFactor[1][i] * xRefinedVel + zRefinedRot;
        }
    }

    //Apply the set required motor power to each drivetrain motor
    static void setDriveMotorPower() {
        for (int i = 0; i < 4; i++) {
            driveWheel[i].Set(ControlMode::PercentOutput, motorPower[i]);
        }
    }
};