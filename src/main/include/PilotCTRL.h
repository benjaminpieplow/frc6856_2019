/*
This file contains code related to interfacing with the pilot. It currently pulls data from the controller, but will be expanded to push data back too
*/


#include "IO.cpp"
#include <frc/Joystick.h>
#include <frc/WPILib.h>

#pragma once

//Raw Values from Joystick (-1 to 1, 0 at rest)
static double xAnalogVel = 0;
static double yAnalogVel = 0;
static double zAnalogRot = 0;

//Refined Raw Values (dampened/curved)
static double xRefinedVel = 0;
static double yRefinedVel = 0;
static double zRefinedRot = 0;

class CTRLInput {
    /*
    This class contains code for pulling and processing code for the robot control. 
    */
    public:

    //Call to input data from controllers
    virtual void getController() {
        xAnalogVel = primaryJoy.GetRawAxis(0);
        yAnalogVel = primaryJoy.GetRawAxis(1);
        zAnalogRot = primaryJoy.GetRawAxis(4);
        //refineInput is called here because it is currently processing a safety measure and therefore cannot be missed.
        //In future versions, the refineInput function will be more flexible and therefore called from other areas of the code.
        refineInput();
    }

    //Refine Input. Current use: Dampen power. Future use: convert to meters/second, "shift gears", tune sensitivities etc.
    virtual void refineInput() {
        
        frc::DigitalInput testLimitSwitch(0);

        //This is a proof-of-concept to test limit switch functionality. A pressed limit switch will disable the robot.
        //if ( testLimitSwitch.Get()  )

            const double modifier = 0.2;
            xRefinedVel = xAnalogVel * modifier;
            yRefinedVel = yAnalogVel * modifier;
            zRefinedRot = zAnalogRot * modifier;

    }

    private:
    frc::Joystick primaryJoy{0};

};