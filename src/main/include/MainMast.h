/**
 * Control of the main mast system
 */

#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

class MainMast
{
    public:
    MainMast();
    ~MainMast();

    //Loweres the mast until it hits the lower limit switch
    void MastHome();

    void MastTestInit();

    void MastTest(double targetPos);


    private:

    

    //Mast Motor Controller
    TalonSRX* m_pMainMastMotor;

    //Mast Homing/Limit Switches
    frc::DigitalInput* m_pLimitSwitchUpper;
    frc::DigitalInput* m_pLimitSwitchLower;
};