/**
 * An attempt to unify sensors on the robot
 * Provides data from limit switches, accelerometer/gyro, etc
 */

#include "RobotIO.h"

LimitSwitchControl::LimitSwitchControl() {}
LimitSwitchControl::~LimitSwitchControl() {}

void LimitSwitchControl::initLimitSwitches()
{
    for (int i = 0; i < 9; i++)
    {
        this->m_pLimitSwitchObjectArr[i] = new frc::DigitalInput(i);
        limSwitchStateArr[i] = false;
    }
}

//Get values from DI Objects and put into Limit Switch Array
void LimitSwitchControl::updateLimitSwitches()
{
    for (int i = 0; i < 9; i++)
    {
        limSwitchStateArr[i] = this->m_pLimitSwitchObjectArr[i]->Get();
    }
}
