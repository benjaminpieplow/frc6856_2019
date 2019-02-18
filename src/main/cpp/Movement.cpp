#include "Movement.h"
#include <iostream>

driveTrain::driveTrain()
{
    //motorPower[0] = 0.0;
    //motorPower[1] = 0.0;
    //motorPower[2] = 0.0;
    //motorPower[3] = 0.0;
    //Feeney said to do this ^ but try this v and see if it works.
    motorPower[4] = {0.0};

 //   TalonSRX* pDriveWheel[4];// = {{10}, {11}, {12}, {13}};
    pDriveWheel[0] = new TalonSRX(10);
    pDriveWheel[1] = new TalonSRX(11);
    pDriveWheel[2] = new TalonSRX(12);
    pDriveWheel[3] = new TalonSRX(13);
}

driveTrain::~driveTrain()
{
    delete pDriveWheel[0];
    delete pDriveWheel[1];
    delete pDriveWheel[2]; 
    delete pDriveWheel[3];

}

void driveTrain::populateMotorVectorFactors() 
{
    for (int i = 0; i < 4; i++) {
        this->motorVectorFactor[0][i] = sin(motorAngles[i]);
        this->motorVectorFactor[1][i] = cos(motorAngles[i]);
    }
}

//Use the values set in populateMotorVectorFactors to set the required power for each motor
void driveTrain::calculateDriveMotorVectors() 
{
    for (int i = 0; i < 4; i++) {
        this->motorPower[i] = -1 * motorVectorFactor[0][i] * yRefinedVel + motorVectorFactor[1][i] * xRefinedVel + zRefinedRot * 0.7;
    }
}

//Apply the set required motor power to each drivetrain motor
void driveTrain::setDriveMotorPower() {
    for (int i = 0; i < 4; i++) {
        //driveWheel[i].Set(ControlMode::PercentOutput, motorPower[i]);
        this->pDriveWheel[i]->Set(ControlMode::PercentOutput, motorPower[i]);

    }
}
