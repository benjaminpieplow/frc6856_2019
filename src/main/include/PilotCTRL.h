/*
This file contains code related to interfacing with the pilot. It currently pulls data from the controller, but will be expanded to push data back too
*/

/* MOVED TO PilotIO.cpp




#include "IO.cpp"
#include <frc/Joystick.h>
#include <frc/WPILib.h>
#include <iostream>

#pragma once


class CTRLInput {

    public:

    //Refined Raw Values (dampened/curved)
    double xRefinedVel = 0;
    double yRefinedVel = 0;
    double zRefinedRot = 0;

    //Call to input data from controllers
    virtual void getController() {
        this->xAnalogVel = primaryJoy.GetRawAxis(0);
        this->yAnalogVel = primaryJoy.GetRawAxis(1);
        this->zAnalogRot = primaryJoy.GetRawAxis(4);
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
            this->xRefinedVel = xAnalogVel * modifier;
            this->yRefinedVel = yAnalogVel * modifier;
            this->zRefinedRot = zAnalogRot * modifier;

    }

    private:
    frc::Joystick primaryJoy{0};

    //Raw Values from Joystick (-1 to 1, 0 at rest)
    double xAnalogVel = 0;
    double yAnalogVel = 0;
    double zAnalogRot = 0;





};

*/