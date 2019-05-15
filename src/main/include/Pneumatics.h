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

    //Switch the Actuator, will only work on the "rising edge" of the trigger pull (so cylinder doesn't flip-flop)
    void togglePneumaticActuator(bool trigger);

    //Set the Actuator State
    void setPneumaticActuator(bool forwards);


    private:
    //Solenoid Ports on PCM
    int m_pSolenoidPortOne;
    int m_pSolenoidPortTwo;
    frc::DoubleSolenoid* m_pActuator;

    //Keep track of current trigger changes
    bool hasChanged = true;
};

class ManualCompressor
{
    /**
     * Not breaking or skirting the rules, just using up the space between the guidlines efficeintly.
     */
    public:
    ManualCompressor();
    ~ManualCompressor();

    void enableCompressor();

    void disableCompressor();

    void setCompressor(bool trigger);

    void toggleCompressor(bool trigger);

    private:

    frc::Compressor *m_pCompressor;

    bool hasChanged = true;
};