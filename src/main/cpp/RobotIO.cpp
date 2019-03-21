/**
 * An attempt to unify sensors on the robot
 * Provides data from limit switches, accelerometer/gyro, etc
 */

#include "RobotIO.h"

LimitSwitchControl::LimitSwitchControl() {
    for (int i = 0; i < 9; i++)
    {
        this->m_pLimitSwitchObjectArr[i] = new frc::DigitalInput(i);
        limSwitchStateArr[i] = false;
    }
}

LimitSwitchControl::~LimitSwitchControl() {}

//Get values from DI Objects and put into Limit Switch Array
void LimitSwitchControl::updateLimitSwitches()
{
    for (int i = 0; i < 9; i++)
    {
        limSwitchStateArr[i] = this->m_pLimitSwitchObjectArr[i]->Get();
    }
}

double Common::twoButtonMotorControl(bool forwardButton, bool reverseButton)
{
    if (reverseButton)
    {
        return -1.0;
    }
    if (forwardButton)
    {
        return 1.0;
    }
    if (!forwardButton && !reverseButton)
    {
        return 0.0;
    }
}

double Common::twoButtonMotorControl(bool forwardButton, bool reverseButton, double forwardPower, double reversePower, double idlePower)
{
    if (reverseButton)
    {
        return reversePower;
    }
    if (forwardButton)
    {
        return forwardPower;
    }
    if (!forwardButton && !reverseButton)
    {
        return idlePower;
    }
}