/**
 * Gripper system on the MainMast
 */

#include "Gripper.h"


Gripper::Gripper()
{
    this->m_pGripperCylinder = new PneumaticActuator(6,7);
    this->m_pHatchCylinder = new PneumaticActuator(4,5);
    
    this->m_pGripperIntakeMotorMaster = new WPI_TalonSRX(20);
    this->m_pGripperIntakeMotorSlave = new WPI_TalonSRX(21);
    
    this->m_pGripperPitchMotor = new WPI_TalonSRX(24);


    this->m_pGripperIntakeMotorMaster->ConfigFactoryDefault();
    this->m_pGripperIntakeMotorSlave->ConfigFactoryDefault();

    this->m_pGripperPitchMotor->ConfigFactoryDefault();

    this->m_pGripperIntakeMotorSlave->Set(ControlMode::Follower, 20);

    //Not sure if this has to be done, or if the slave covers it
    this->m_pGripperPitchMotor->SetNeutralMode(NeutralMode::Brake);
}

Gripper::~Gripper()
{
    this->m_pGripperIntakeMotorMaster->DestroyAllMotControllers();
}

/**
 * Set power on the intake wheels
 */
void Gripper::setGripperIntakeWheels(double motorPower)
{
    this->m_pGripperIntakeMotorMaster->Set(ControlMode::PercentOutput, motorPower);
}

void Gripper::setGripperPitchPower(double motorPower)
{
    this->m_pGripperPitchMotor->Set(ControlMode::PercentOutput, motorPower);
}

/**
 * Pass the raw button input to control toggling of the pneumatic cylinder
 */
void Gripper::toggleGripperClaw(bool button)
{
    this->m_pGripperCylinder->togglePneumaticActuator(button);
}

void Gripper::toggleHatchLatch(bool button)
{
    this->m_pHatchCylinder->togglePneumaticActuator(button);
}

void Gripper::setHatchLatch(bool button)
{
    this->m_pHatchCylinder->setPneumaticActuator(button);
}