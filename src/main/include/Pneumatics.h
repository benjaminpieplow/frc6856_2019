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

    //Switch the Actuator
    void togglePneumaticActuator();


    private:
    frc::DoubleSolenoid solenoid {4,5};
    bool lastState = false;
};