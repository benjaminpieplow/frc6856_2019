#pragma once

#include <frc/WPILib.h>
#include "GlobalVars.h"


/**
 * Limit Switches are contained within the m_pLimitSwitchObjects.
 * Currently, all 10 DigitalInput pins are setup as limit switches
 */
class LimitSwitchControl
{
    public:
    LimitSwitchControl();
    ~LimitSwitchControl();

    //Create Limit Switches and Zero Array
    void initLimitSwitches();

    //Get values from DI Objects and put into Limit Switch Array
    void updateLimitSwitches();
    
    private:
    frc::DigitalInput* m_pLimitSwitchObjectArr[10];
};

class Common
{
    public:
    //Returns 0 if no input, 1 if forwards, -1 if reverse
    double twoButtonMotorControl(bool forwardButton, bool reverseButton);

    //Similar to twoButtonMotorControl but allows specific power levels (this is a surprise tool that will help us later)
    double twoButtonMotorControl(bool forwardButton, bool reverseButton, double forwardPower, double reversePower, double idlePower);
};