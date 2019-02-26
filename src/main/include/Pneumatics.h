/**
 * All Air Actuators!
 * My first attempt at making a "template" class, this (in theory) will work for all pneumatic actuators on the robot.
 */

#pragma once

#include <frc/DoubleSolenoid.h>

class PneumaticActuator
{
    public:
    PneumaticActuator();
    ~PneumaticActuator();

    //Switch the Actuator, will only work on the "rising edge" of the trigger pull
    void togglePneumaticActuator(bool trigger);


    private:
    frc::DoubleSolenoid solenoid {4,5};

    //Keep track of current trigger changes
    bool hasChanged = true;
};