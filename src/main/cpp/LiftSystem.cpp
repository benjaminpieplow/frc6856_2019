/**
 * Controls for the robot lift and lower mechanisms
 */


#include "LiftSystem.h"


LiftSystem::LiftSystem()
{
    this->m_pRearLiftMotor = new WPI_TalonSRX(34);
    
    this->m_pFrontLiftMotorMaster = new WPI_TalonSRX(26);
    this->m_pFrontLiftMotorSlave = new WPI_TalonSRX(27);

    this->m_pFrontArmWheelMaster = new WPI_VictorSPX(30);
    this->m_pFrontArmWheelSlave = new WPI_VictorSPX(31);

    //Nuke the controllers
    this->m_pRearLiftMotor->ConfigFactoryDefault();
    this->m_pFrontLiftMotorMaster->ConfigFactoryDefault();
    this->m_pFrontLiftMotorSlave->ConfigFactoryDefault();
    this->m_pFrontArmWheelMaster->ConfigFactoryDefault();
    this->m_pFrontArmWheelSlave->ConfigFactoryDefault();

    //Slave the slave controllers
    this->m_pFrontArmWheelSlave->Set(ControlMode::Follower, 30);
    this->m_pFrontLiftMotorSlave->Set(ControlMode::Follower, 26);
}

LiftSystem::~LiftSystem()
{
    //Just reboot the Rio
}


void LiftSystem::SetRearLiftPower(double motorPower)
{
    this->m_pRearLiftMotor->Set(ControlMode::PercentOutput, motorPower);
}

void LiftSystem::SetFrontArmPower(double motorPower)
{
    this->m_pFrontLiftMotorMaster->Set(ControlMode::PercentOutput, motorPower);
}

void LiftSystem::SetFrontArmWheelPower(double motorPower)
{
    this->m_pFrontArmWheelMaster->Set(ControlMode::PercentOutput, motorPower);
}
