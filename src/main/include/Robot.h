/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


//Not my code, not my comment

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Solenoid.h>
#include <frc/Compressor.h>
#include "Movement.h"
#include "DriveTeamIO.h"
#include "MainMast.h"
#include "Pneumatics.h"
#include "RobotIO.h"
#include "LiftSystem.h"
#include "Gripper.h"



class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  //Create Limit Switches
  LimitSwitchControl m_limitSwitch;

  //Common Methods
  Common m_common;

  ManualCompressor m_pManualCompressor;
  
  PilotInput m_pilotInput;
  OperatorInput m_operatorInput;

  //Create Drivetrain
  //omniDrive m_primaryDrive;
  tankDrive m_pTankDrive;

  //Create a Mast
  MainMast m_mainMast;

  //Create a lift system 
  LiftSystem m_liftSystem;

  //Create a gripper
  Gripper m_gripper;
  
};
