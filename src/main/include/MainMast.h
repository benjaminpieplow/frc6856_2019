/**
 * Control of the main mast system
 */

#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include "Pneumatics.h"

class MainMast
{
    public:
    MainMast();
    ~MainMast();

    void MainMastInit();

    //Loweres the mast until it hits the lower limit switch
    void MastHome();

    void MastTestInit();

    void MastTest(double targotPos);

    void MastManualControl(double targetPower);

    void updateLimitSwitches();

    bool getLimitSwitch(int limIndex);

    private:
    //Mast Motor Controller
    TalonSRX* m_pMainMastMotor;

    //Mast Homing/Limit Switches
    frc::DigitalInput* m_pLimitSwitchObjects[10];

    //Pneumatic Brake for Mast
    PneumaticActuator* m_pBrakePneumatic;

    //PWM Pin for Servo Brake
    frc::PWM* m_pBrakeServo;

    //Mast Limit Switch states
    bool m_pLimitSwitchState[10];

};