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

    //Set Gripper Power
    void setGripperIntakeWheels(double motorPower);

    void setGripperPitchPower(double motorPower);

    void toggleGripperClaw(bool button);

    private:
    //Cylinder for the gripper
    PneumaticActuator* m_pGripperCylinder;

    //Motor for the gripper pitch
    WPI_TalonSRX* m_pGripperPitchMotor;

    //Motors for the grippper wheels
    WPI_TalonSRX* m_pGripperIntakeMotorMaster;
    WPI_TalonSRX* m_pGripperIntakeMotorSlave;
};