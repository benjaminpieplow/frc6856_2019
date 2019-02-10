/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <ctre/Phoenix.h>
#include <math.h>
#include <iostream>
#include "BotMath.h"

//INSTATNTIANTING MOTOR CONTROLLERS | USING TALONSRX'S | MOTOR NAMING SYSTEM BELOW NOTES
TalonSRX wheel0 = {10};
TalonSRX wheel1 = {11};
TalonSRX wheel2 = {12};
TalonSRX wheel3 = {13};
//

/*
 * 
 * This sample program shows how to control a motor using a joystick. In the
 * operator control part of the program, the joystick is read and the value is
 * written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as
 * range from -1 to 1 making it easy to work together.
 * 
 * 
 * BOT WHEEL SYSTEM DIAGRAM:
 * 
 *     FRONT
 *    0----3
 *    |    |
 *    1----2
 *     BACK
 *
 * 
 */

class Robot : public frc::TimedRobot {

 public:

  void TeleopPeriodic() override {
  BotMath::desiredXVelocity = 0.20 * m_stick.GetRawAxis(0);
  BotMath::desiredYVelocity = 0.20 * m_stick.GetRawAxis(1);
  BotMath::desiredZRVelocity = 0.20 * m_stick.GetRawAxis(4);
  std::cout << "Desired X Velocity:";
  std::cout << BotMath::desiredXVelocity;
  std::cout << "Desired Y Velocity:";
  std::cout << BotMath::desiredYVelocity;
  std::cout << "Desired Zr Velocity:";
  std::cout << BotMath::desiredZRVelocity;

//SETTING SPEEDS FOR WHEELS
   wheel0.Set(ControlMode::PercentOutput, (-0.7*BotMath::desiredYVelocity) - (-0.7*BotMath::desiredXVelocity) + BotMath::desiredZRVelocity);
   wheel1.Set(ControlMode::PercentOutput, (-0.7*BotMath::desiredYVelocity) - (0.7*BotMath::desiredXVelocity) + BotMath::desiredZRVelocity);
   wheel2.Set(ControlMode::PercentOutput, (0.7*BotMath::desiredYVelocity) - (  0.7*BotMath::desiredXVelocity) + BotMath::desiredZRVelocity);
   wheel3.Set(ControlMode::PercentOutput, (0.7*BotMath::desiredYVelocity) - (-0.7*BotMath::desiredXVelocity) + BotMath::desiredZRVelocity);
}

//CLASS TO SET UP ROBOT
bool InitRobot() {
  return true;
}

 private:
  frc::Joystick m_stick{0};

};

#ifndef RUNNING_FRC_TESTS
int main() { 

  return frc::StartRobot<Robot>();

  }
#endif