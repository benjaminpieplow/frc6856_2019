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
    this->xAnalogVel = primaryJoy.GetRawAxis(0);
    this->yAnalogVel = primaryJoy.GetRawAxis(1);
    this->zAnalogRot = primaryJoy.GetRawAxis(4);
    //refineInput is called here because it is currently processing a safety measure and therefore cannot be missed.
    //In future versions, the refineInput function will be more flexible and therefore called from other areas of the code.
    refineInput();
}

//Refine Input. Current use: Dampen power. Future use: convert to meters/second, "shift gears", tune sensitivities etc.
void PilotInput::refineInput()
{
    //modifier is currently set to calm the robot down, get permission from Dan or Ray before exceeding 0.25
    const double modifier = 1.0;
    xRefinedVel = PilotInput::presPolSquare(xAnalogVel) * 1;
    yRefinedVel = PilotInput::presPolSquare(yAnalogVel) * 1;
    zRefinedRot = PilotInput::presPolSquare(zAnalogRot) * 1;
}

bool PilotInput::getCtrlButton(int ctrlButton)
{
    return primaryJoy.GetRawButton(ctrlButton);
}


double PilotInput::presPolSquare(double toSquare)
{
    if(toSquare > 0)
    {
        return (toSquare * toSquare);
    }
    else if(toSquare < 0)
    {
        return (toSquare * toSquare * -1);
    }
    else if (toSquare = 0)
    {
        return 0;
    }
}

/**
 * OPERATOR INPUT
 */

OperatorInput::OperatorInput()
{
    //Still nothing!
}

OperatorInput::~OperatorInput()
{
    //Should probably do this, shouldn't I?
}

//Returns an int with the current operator mode (drive vs climb)
int OperatorInput::getControlMode()
{
    return this->m_pControlMode;
}

//Allows Operator to toggle control mode
void OperatorInput::toggleControlMode(bool toggleButton)
{
  //If the button is pressed AND the check-bit is enabled, change the control mode and flip the check latch
  if (toggleButton && this->m_pControlModeHasChanged)
  {
    //Reverse the actuator
    if (this->m_pControlMode == 0)
    {
      this->m_pControlMode = 1;
    }
    else
    {
      this->m_pControlMode = 0;
    }
    //Disables this IF statement until the trigger is released (prevents cycling the cylinder when trigger is held for >10ms)
    this->m_pControlModeHasChanged = false;
  }

  //If the trigger is not being pulled, re-enable the toggle
  if (!toggleButton && !this->m_pControlModeHasChanged)
  {
    this->m_pControlModeHasChanged = true;
  }

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

bool OperatorInput::getJoyButton(int joyButton)
{
    return operatorJoy.GetRawButton(joyButton);
}

/**
 * Returns Trigger Position
 */
bool OperatorInput::getJoyTrigger()
{
    return operatorJoy.GetTrigger();
}
