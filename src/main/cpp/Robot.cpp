/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Camera.h"
#include "Robot.h"
#include <iostream>
#include "PilotCTRL.h"
#include "Movement.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include "IO.h"
#include <frc/Encoder.h>

//making global Variables
static driveTrain primaryDrive;
//INSTANTIAING THE MOTOR ENCODERS
//PARAMTER MEANINGS (DIGITAL INPUT, INVERT COUNT DIRECTION, ACCURACY)
static frc::Encoder frontLeftEncoder(0, false, frc::Encoder::EncodingType::k4X);
static frc::Encoder frontRightEncoder(3, false, frc::Encoder::EncodingType::k4X);
static frc::Encoder backleftEncoder(1, false, frc::Encoder::EncodingType::k4X);
static frc::Encoder backRightEncoder(2, false, frc::Encoder::EncodingType::k4X);

void Robot::RobotInit()
{

  //INSTANTIATING THE DRIVETRAIN CLASS

  //This code is here by default and therefore should not be removed
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  //Calculate motor vector factors
  primaryDrive.populateMotorVectorFactors();

  //streaming cameras
  botVideo::StreamBotCameras();

  //Instantiating drivetrain motor class
  driveMotorIO driveEncoders();
  //******VERY IMPORTANT HERE******* || THIS SETS THE DISTANCE PER PULSE ON THE SQUARE WAVE FREQUNCIES FOR THE ENCODERS
  //The next Line sets every time 24 'clicks' or degrees pass, the encoder send a pulse
  driveEncoders().setAllDistancePerPulse(24);

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

void Robot::TeleopInit()
{
}

void Robot::TeleopPeriodic()
{

  //Define pilotInput and Drivetrain as object-ish things
  CTRLInput pilotInput;

  //Get Pilot's input data
  pilotInput.getController();

  //Run input refinement (dampen, bellcurve, etc)
  pilotInput.refineInput();

  //Calculate per-motor vectors
  primaryDrive.calculateDriveMotorVectors();

  //Set Update ESCs via CAN
  primaryDrive.setDriveMotorPower();
}

void Robot::TestPeriodic()
{
}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
