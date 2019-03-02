#include "Pneumatics.h"


PneumaticActuator::PneumaticActuator()
{
  this->solenoid.Set(frc::DoubleSolenoid::kForward);
}


PneumaticActuator::~PneumaticActuator()
{
  //Meh
}


void PneumaticActuator::togglePneumaticActuator(bool trigger)
{
  //If the trigger is pulled AND a switch has not already happened this trigger-pull
  if (trigger && this->hasChanged)
  {
    //Reverse the actuator
    if (this->solenoid.Get() == frc::DoubleSolenoid::kForward)
    {
      this->solenoid.Set(frc::DoubleSolenoid::kReverse);
    }
    else
    {
      this->solenoid.Set(frc::DoubleSolenoid::kForward);
    }
    //Disables this IF statement until the trigger is released (prevents cycling the cylinder when trigger is held for >10ms)
    this->hasChanged = false;
  }

  //If the trigger is not being pulled, re-enable the toggle
  if (!trigger && !this->hasChanged)
  {
    this->hasChanged = true;
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


