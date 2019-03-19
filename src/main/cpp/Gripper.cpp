/**
 * Gripper system on the MainMast
 */

#include "Gripper.h"


Gripper::Gripper()
{

}

/**
 * Set power on the intake wheels
 */
void Gripper::setGripperIntakeWheels(double motorPower)
{
    this->m_pGripperIntakeMotorMaster->Set(ControlMode::PercentOutput, motorPower);
}

/**
 * Pass the raw button input to controll toggling of the pneumatic cylinder
 */
void Gripper::toggleGripperClaw(bool button)
{
    this->m_pGripperCylinder->togglePneumaticActuator(button);
}
