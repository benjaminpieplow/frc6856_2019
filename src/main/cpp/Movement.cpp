/*
*/


#include "Movement.h"
#include <iostream>
#include <DriveTeamIO.h>
#include "Robot.h"
#include "GlobalVars.h"

driveTrain::driveTrain()
{
    //Initializes the set Motor Power at 0, to avoid any jumps
    motorPower[4] = {0.0};
    
    //Create an array of TalonSRX objects for drive wheels, these will be addressed by the motors
    //Note: Switched from TalonSRX to WPI_TalonSRX, untested as of yet
    pDriveWheel[0] = new WPI_TalonSRX(10);
    pDriveWheel[1] = new WPI_TalonSRX(11);
    pDriveWheel[2] = new WPI_TalonSRX(12);
    pDriveWheel[3] = new WPI_TalonSRX(13);

    for (int i = 0; i < 4; i++) {
        //driveWheel[i].Set(ControlMode::PercentOutput, motorPower[i]);
        this->pDriveWheel[i]->ConfigFactoryDefault(10);
        this->pDriveWheel[i]->ConfigVoltageCompSaturation(12, 10);
    }
}

driveTrain::~driveTrain()
{
    //Delete old Wheel objects
    delete pDriveWheel[0];
    delete pDriveWheel[1];
    delete pDriveWheel[2]; 
    delete pDriveWheel[3];

}




/**
 * Uses motor anlges to calculate magnitudes for X and Y drive axis, used on each motor
 * 2-D array has components [X/Y][MOTOR] where [1][3] would be the Y power factor for motor 3
 */
void driveTrain::populateMotorVectorFactors() 
{
    for (int i = 0; i < 4; i++) {
        this->motorVectorFactor[0][i] = sin(motorAngles[i]);
        this->motorVectorFactor[1][i] = cos(motorAngles[i]);
    }
}

/**
 * Use the values set in populateMotorVectorFactors to set the required power for each motor
 * Called once per robot packet
 */
void driveTrain::calculateDriveMotorVectors() 
{
    for (int i = 0; i < 4; i++) {
        //xRefinedVel, yRefinedVel and zRefinedRot
        this->motorPower[i] = -1 * this->motorVectorFactor[0][i] * yRefinedVel + this->motorVectorFactor[1][i] * xRefinedVel + zRefinedRot * 0.5;
    }
}

/**
 * Apply the set required motor power to each drivetrain motor
 * Called once per robot packet
 */
void driveTrain::setDriveMotorPower() {
    for (int i = 0; i < 4; i++) {
        //driveWheel[i].Set(ControlMode::PercentOutput, motorPower[i]);
        this->pDriveWheel[i]->Set(ControlMode::PercentOutput, motorPower[i]);
        //this->pDriveWheel[i]->Set(ControlMode::Current, motorPower[i]);
  
    }
}
