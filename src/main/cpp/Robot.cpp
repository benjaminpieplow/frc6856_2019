/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Camera.h"
#include "Robot.h"
#include "Movement.h"
#include "MainMast.h"

/**
 * Runs at RoboRIO startup, regardless of mode
 * m_chooser is FRC code, the rest setups variables and runtime objects
*/
void Robot::RobotInit() {

  //This code is here by default and therefore should not be removed
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  //Calculate motor vector factors
  m_primaryDrive.populateMotorVectorFactors();

  //Start Streaming both cameras using default settings
  botVideo::StreamBotCameras();

  m_mainMast.nukeControllers();
  
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit()
{
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom)
  {
    // Custom Auto goes here
  }
  else
  {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic()
{
  if (m_autoSelected == kAutoNameCustom)
  {
    // Custom Auto goes here
  }
  else
  {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {
  //m_mainMast.MastTestInit();
  std::cout << "TeleopInit Complete";
}

void Robot::TeleopPeriodic()
{
  //Get latest Limit Switch data
  m_mainMast.updateLimitSwitches();

  //Get Pilot's input data
  Robot::m_pilotInput.getController();

  //Calculate per-motor vectors
  m_primaryDrive.calculateDriveMotorVectors();

  //Set Update ESCs via CAN
  m_primaryDrive.setDriveMotorPower();

  //Toggle Pneumatic Actuator by passing input from Operator Joystick
  testSolenoid.togglePneumaticActuator(m_operatorInput.getJoyTrigger());

  //Set Main Mast Power
  m_mainMast.MastManualControl(m_operatorInput.getJoyY());
  //double targetPos;
  //targetPos = m_operatorInput.getJoyY() * 360 * 1.0;
  //m_mainMast.MastTest(targetPos);

  if (!m_mainMast.getLimitSwitch(2))
  {
    testSolenoid.setPneumaticActuator(true);
  }
  else
  {
    testSolenoid.setPneumaticActuator(false);
  }
}

void Robot::TestPeriodic() {
  
}

#ifndef RUNNING_FRC_TESTS

int main()
{  
  return frc::StartRobot<Robot>();
}
#endif
