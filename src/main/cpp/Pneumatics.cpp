#include "Pneumatics.h"


PneumaticActuator::PneumaticActuator()
{
    //Construct PneumaticActuator
}



void PneumaticActuator::togglePneumaticActuator()
{
  if (this->solenoid.Get() == frc::DoubleSolenoid::kForward)
  {
    this->solenoid.Set(frc::DoubleSolenoid::kReverse);
  }
  else
  {
    this->solenoid.Set(frc::DoubleSolenoid::kForward);
  }
}

/**
 * 
  if (m_pilotInput.getButton()) {
    testDoubleSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
  }
  else
  {
    testDoubleSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
  }
 */


