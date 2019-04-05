#pragma once


#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include "Pneumatics.h"
#include "GlobalVars.h"
#include "RobotIO.h"


class LiftSystem
{

    public:
    LiftSystem();
    ~LiftSystem();

    void SetRearLiftPower(double motorPower);

    void SetFrontArmPower(double motorPower);

    void SetFrontArmWheelPower(double motorPower);

    WPI_TalonSRX* m_pRearLiftMotor;
    WPI_TalonSRX* m_pFrontLiftMotorMaster;
    WPI_TalonSRX* m_pFrontLiftMotorSlave;
    WPI_VictorSPX* m_pFrontArmWheelMaster;
    WPI_VictorSPX* m_pFrontArmWheelSlave;

};