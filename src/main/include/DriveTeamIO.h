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

class OperatorInput
{
    public:
    OperatorInput();
    ~OperatorInput();

    double getJoyX();

    double getJoyY();

    bool getJoyTrigger();

    private:
    //Operator's Joystick
    frc::Joystick operatorJoy{1};

}