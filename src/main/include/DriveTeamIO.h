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

    void initGlobalVars();

    //Call to input data from controllers
    void getController();

    //Refine Input. Current use: Dampen power. Future use: convert to meters/second, "shift gears", tune sensitivities etc.
    void refineInput();

    private:
    //Pilot's Joystick
    frc::Joystick primaryJoy{0};

    //Raw Values from Joystick (-1 to 1, 0 at rest)
    double xAnalogVel = 0;
    double yAnalogVel = 0;
    double zAnalogRot = 0;


};