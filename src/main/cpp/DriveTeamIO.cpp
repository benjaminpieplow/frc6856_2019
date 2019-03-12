/*
    Welcome to PilotIO.cpp! This file contains the following classes:
        PilotInput: Get controller input from Pilot; refine into something useful
        CameraFeed: Pilots need to C! This class lets them do that
*/

#include "Movement.h"
#include "DriveTeamIO.h"
#include "GlobalVars.h"

//Constructor (empty)
PilotInput::PilotInput () {}

//Destructor (empty - like my soul)
PilotInput::~PilotInput () {}

//Call to load controller joystick positions into object's properties
void PilotInput::getController()
{
    this->xAnalogVel = primaryJoy.GetRawAxis(0) * -1;
    this->yAnalogVel = primaryJoy.GetRawAxis(1) * -1;
    this->zAnalogRot = primaryJoy.GetRawAxis(4);
    //refineInput is called here because it is currently processing a safety measure and therefore cannot be missed.
    //In future versions, the refineInput function will be more flexible and therefore called from other areas of the code.
    refineInput();
}

//Refine Input. Current use: Dampen power. Future use: convert to meters/second, "shift gears", tune sensitivities etc.
void PilotInput::refineInput()
{
    //modifier is currently set to calm the robot down, get permission from Dan or Ray before exceeding 0.25
    const double modifier = 0.3;
    xRefinedVel = xAnalogVel * modifier;
    yRefinedVel = yAnalogVel * modifier;
    zRefinedRot = zAnalogRot * modifier;
}

bool PilotInput::getButton()
{
    return primaryJoy.GetRawButton(5);
}

OperatorInput::OperatorInput()
{
    //Still nothing!
}

OperatorInput::~OperatorInput()
{
    //Should probably do this, shouldn't I?
}


/**
 * Returns the Joystick X axis
 * Currently Used for testing Power Control
 */
double OperatorInput::getJoyX()
{
    return operatorJoy.GetRawAxis(0);
}

/**
 * Returns Joystick Y Axis
*/
double OperatorInput::getJoyY()
{
    return operatorJoy.GetRawAxis(1);
}

/**
 * Returns Trigger Position
 * Currently used for Pneumatic Actuator
 */
bool OperatorInput::getJoyTrigger()
{
    return operatorJoy.GetTrigger();
}
