/**
 * Controls for the robot lift and lower mechanisms
 */

#include "LiftSystem.h"


LiftSystem::LiftSystem()
{
    this->m_pRearLiftMotor = new WPI_TalonSRX(20);
    
    this->m_pFrontLiftMotorMaster = new WPI_TalonSRX(21);
    this->m_pFrontLiftMotorSlave = new WPI_TalonSRX(22);

    this->m_pFrontArmWheelMaster = new WPI_TalonSRX(30);
    this->m_pFrontArmWheelSlave = new WPI_TalonSRX(31);

    //Nuke the controllers
    this->m_pRearLiftMotor->ConfigFactoryDefault();
    this->m_pFrontLiftMotorMaster->ConfigFactoryDefault();
    this->m_pFrontLiftMotorSlave->ConfigFactoryDefault();
    this->m_pFrontArmWheelMaster->ConfigFactoryDefault();
    this->m_pFrontArmWheelSlave->ConfigFactoryDefault();

    //Slave the slave controllers
    this->m_pFrontArmWheelSlave->Set(ControlMode::Follower, 21);
    this->m_pFrontLiftMotorSlave->Set(ControlMode::Follower, 30);
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