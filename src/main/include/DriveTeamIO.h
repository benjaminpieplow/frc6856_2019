#pragma once

#include <frc/Joystick.h>
#include <frc/WPILib.h>

class PilotInput {
    /*
    This class is for aquiring and manipulating data from the pilot's controller
    */

    public:
    PilotInput();
    ~PilotInput();

    //Call to input data from controllers
    void getController();

    //Refine Input. Current use: Dampen power. Future use: convert to meters/second, "shift gears", tune sensitivities etc.
    void refineInput();

    //Get a button state, currently for test
    bool getButton();

    private:
    //Pilot's Controller
    frc::XboxController primaryJoy{0};

    //Raw Values from Joystick (-1 to 1, 0 at rest)
    double xAnalogVel = 0;
    double yAnalogVel = 0;
    double zAnalogRot = 0;

};


/**
 * OperatorInput is designed to pull data from a joystick controlled by the operator
 * Currently used for all non-driving functions: Pneumatic and Motor control
 */
class OperatorInput
{
    public:
    OperatorInput();
    ~OperatorInput();

    //Returns Joystick X Axis
    double getJoyX();

    //Returns Joystick Y Axis
    double getJoyY();

    //Returns Joystick Trigger
    bool getJoyTrigger();

    private:
    //Operator's Joystick
    frc::Joystick operatorJoy{1};

};