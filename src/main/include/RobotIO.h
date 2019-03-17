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