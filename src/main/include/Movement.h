/*
This file contains code to actuate movements of the robot, like omniDrive and TankDrive
*/
#pragma once

#include <frc/TimedRobot.h>
#include "ctre/Phoenix.h"
#include <math.h>


//Motor power is a value from -1 to 1. Basic implementation sets this from the joystick input, but in future it can be influenced by PID controllers for stabilizing
//See RobotMappings.txt for info on control mappings
//ToDo: Create RobotMappings.txt



class omniDrive
{
    public:
    omniDrive();
    ~omniDrive();

    //This code uses the motor angles, currently set above (may be ported to .conf file in the future), to calculate the applied power factors
    void populateMotorVectorFactors();

    //Use the values set in populateMotorVectorFactors to set the required power for each motor
    void calculateDriveMotorVectors();

    //Apply the set required motor power to each omniDrive motor
    void setDriveMotorPower();

    //Motor power is a value from -1 to 1. Basic implementation sets this from the joystick input, but in future it can be influenced by PID controllers for stabilizing
    double motorPower[4];

    //
    WPI_TalonSRX* pDriveWheel[4];

    //sin(theta) where theta is wheel angle where [0][i] will be sin (Y-axis) and [1][i] will be cos (X-axis)
    double motorVectorFactor[2][4];

    //Wheel Angles in Radians. Useful for calculating vectors and stuff, hence global.
    const double motorAngles[4] = {0.78539816339744830961566084581988, 2.3561944901923449288469825374596, 3.9269908169872415480783042290994, 5.4977871437821381673096259207391};
    //Note: Variable is static, if it changes during runtime it's build team's problem

};


class tankDrive
/**
 * Note: We coded our own tank drive. Yes, I know, FRC has a tank drive available.
 * But if something went wrong, I needed to fix it, so I had to know *exactly* how it worked.
 */
{
    public:
    tankDrive();
    ~tankDrive();
    void setTankDrivePower(double yVel, double zRot);

    private:
    WPI_TalonSRX* pDriveWheel[4];
};