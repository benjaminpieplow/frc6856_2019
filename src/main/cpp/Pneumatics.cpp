#include "Pneumatics.h"


PneumaticActuator::PneumaticActuator(int solenoidForwardPort, int solenoidReversePort)
{
  this->m_pActuator = new frc::DoubleSolenoid (solenoidForwardPort,solenoidReversePort);
  this->m_pActuator->Set(frc::DoubleSolenoid::kForward);
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
    if (this->m_pActuator->Get() == frc::DoubleSolenoid::kForward)
    {
      this->m_pActuator->Set(frc::DoubleSolenoid::kReverse);
    }
    else
    {
      this->m_pActuator->Set(frc::DoubleSolenoid::kForward);
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

void PneumaticActuator::setPneumaticActuator(bool forwards)
{
  if (forwards)
  {
    this->m_pActuator->Set(frc::DoubleSolenoid::kForward);
  }
  else
  {
    this->m_pActuator->Set(frc::DoubleSolenoid::kReverse);
  }
}



ManualCompressor::ManualCompressor()
{
  this->m_pCompressor = new frc::Compressor(0);
}

ManualCompressor::~ManualCompressor()
{
  //Nope
}

void ManualCompressor::enableCompressor()
{
  this->m_pCompressor->Start();
}

void ManualCompressor::disableCompressor()
{
  this->m_pCompressor->Stop();
}

void ManualCompressor::toggleCompressor(bool trigger)
{
  //If the trigger is pulled AND a switch has not already happened this trigger-pull
  if (trigger && this->hasChanged)
  {
    //Toggle the compressor
    if (this->m_pCompressor->GetClosedLoopControl())
    { //Runs if Compressor is Enabled
      this->m_pCompressor->Stop();
    }
    else
    { //Runs if Compressor is disabled
      this->m_pCompressor->Start();
    }

    //Disables this IF statement until the trigger is released (prevents cycling the compressor when trigger is held for >10ms)
    this->hasChanged = false;
  }

  //If the trigger is not being pulled, re-enable the toggle
  if (!trigger && !this->hasChanged)
  {
    this->hasChanged = true;
  }

}