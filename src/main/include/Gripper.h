/**
 * Gripper systems on the MainMast
 */

#pragma once

#include "Pneumatics.h"
#include "ctre/Phoenix.h"


class Gripper
{
    public:
    Gripper();
    ~Gripper();

    void setGripperIntakeWheels(double motorPower);

    void toggleGripperClaw(bool button);

    private:
    //Cylinder for the gripper
    PneumaticActuator* m_pGripperCylinder;

    //Motors for the grippper wheels
    WPI_TalonSRX* m_pGripperIntakeMotorMaster;
    WPI_TalonSRX* m_pGripperIntakeMotorSlave;
};