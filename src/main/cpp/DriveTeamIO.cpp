/*
    Welcome to PilotIO.cpp! This file contains the following classes:
        PilotInput: Get controller input from Pilot; refine into something useful
        CameraFeed: Pilots need to C! This class lets them do that
*/

#include "Movement.h"
#include "DriveTeamIO.h"


//Call to input data from controllers
void PilotInput::getController() {
    this->xAnalogVel = this->primaryJoy.GetRawAxis(0);
    this->yAnalogVel = this->primaryJoy.GetRawAxis(1);
    this->zAnalogRot = this->primaryJoy.GetRawAxis(4);
    //refineInput is called here because it is currently processing a safety measure and therefore cannot be missed.
    //In future versions, the refineInput function will be more flexible and therefore called from other areas of the code.
    refineInput();
}

//Refine Input. Current use: Dampen power. Future use: convert to meters/second, "shift gears", tune sensitivities etc.
void PilotInput::refineInput() {
    
    frc::DigitalInput testLimitSwitch(0);

    //This is a proof-of-concept to test limit switch functionality. A pressed limit switch will disable the robot.
    //if ( testLimitSwitch.Get()  )

        const double modifier = 0.2;
        this->xRefinedVel = xAnalogVel * modifier;
        this->yRefinedVel = yAnalogVel * modifier;
        this->zRefinedRot = zAnalogRot * modifier;

}


