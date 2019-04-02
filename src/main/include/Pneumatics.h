/**
 * All Air Actuators!
 * My first attempt at making a "template" class, this (in theory) will work for all pneumatic actuators on the robot.
 */

#pragma once

#include <frc/DoubleSolenoid.h>
#include <iostream>
#include <frc/Compressor.h>

class PneumaticActuator
{
    public:
    PneumaticActuator(int solenoidForwardPort, int solenoidReversePort);
    ~PneumaticActuator();

    //Switch the Actuator, will only work on the "rising edge" of the trigger pull
    void togglePneumaticActuator(bool trigger);

    //Set the Actuator State
    void setPneumaticActuator(bool forwards);


    private:
    int m_pSolenoidPortOne;
    int m_pSolenoidPortTwo;
    frc::DoubleSolenoid* m_pActuator;

    //Keep track of current trigger changes
    bool hasChanged = true;
};

class ManualCompressor
{
    public:
    ManualCompressor();
    ~ManualCompressor();

    void initCompressor();

    void enableCompressor();

    void disableCompressor();

    void toggleCompressor(bool trigger);

    private:

    frc::Compressor *m_pCompressor;

    bool systemPrimed = false;
    bool hasChanged = true;
};