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

  //Calculate motor vector factors (Omni)
  //m_primaryDrive.populateMotorVectorFactors();

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
void Robot::RobotPeriodic()
{}

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
}

void Robot::AutonomousPeriodic()
{
  TeleopPeriodic();
}

void Robot::TeleopInit() {
  //m_mainMast.MastTestInit();
  std::cout << "TeleopInit Complete";
}

void Robot::TeleopPeriodic()
{
  //Get latest Limit Switch data
  m_limitSwitch.updateLimitSwitches();

  m_pManualCompressor.toggleCompressor(m_operatorInput.getJoyButton(11));

  //Get Pilot's input data
  Robot::m_pilotInput.getController();

  //Send Tank Power to Motors
  //m_pTankDrive.setTankDrivePower(yRefinedVel, zRefinedRot);

  //HOTFIX: TankDriveOverride
  if(m_pilotInput.getCtrlButton(1))
  {//If Override is pushed, set full forward
    m_pTankDrive.setTankDrivePower(-1.0, 0);
  }
  else
  {
    m_pTankDrive.setTankDrivePower(yRefinedVel, zRefinedRot);
  }

  //Calculate per-motor vectors (Omni)
  //m_primaryDrive.calculateDriveMotorVectors();

  //Set Update ESCs via CAN (Omni)
  //m_primaryDrive.setDriveMotorPower();

  //If the pilot hits the button, toggle the gripper
  m_gripper.toggleGripperClaw(m_pilotInput.getCtrlButton(10));
  
  //Set Gripper Wheel Speed
  m_gripper.setGripperIntakeWheels(m_common.twoButtonMotorControl(m_pilotInput.getCtrlButton(6), m_pilotInput.getCtrlButton(5), 1, -0.3, 0));

  //Front Intake is drive, therefor persistant
  m_liftSystem.SetFrontArmWheelPower(m_common.twoButtonMotorControl(m_operatorInput.getJoyButton(2), m_operatorInput.getJoyTrigger()));

  //Trigger now does the HatchLatch
  m_gripper.setHatchLatch(m_operatorInput.getJoyTrigger());
 
  //Toggles between DRIVE and LIFT
  m_operatorInput.toggleControlMode(m_operatorInput.getJoyButton(6));

  
  //Divide the code into the two drive modes (DRIVE and LIFT)
  if (m_operatorInput.getControlMode() == 0) //If in DRIVE mode
  {
    /**
     * SET Motor Power Levels for  DRIVE mode
     */
    m_mainMast.MastLimitControl(m_operatorInput.getJoyY(), limSwitchStateArr[0]);
    m_gripper.setGripperPitchPower(m_operatorInput.getJoyX());

    /**
     * SET Motor Power Levels TO ZERO for LIFT mode
     */
    m_liftSystem.SetFrontArmPower(0);
    m_liftSystem.SetRearLiftPower(0);
  }
  else if (m_operatorInput.getControlMode() == 1) //If in LIFT mode
  {
    /**
     * SET Motor Power levels for LIFT mode
     */
    //Set Front Lift Arm Power to Joystick Y axis
    m_liftSystem.SetFrontArmPower(m_operatorInput.getJoyY() * 0.5);
    //m_liftSystem.SetRearLiftPower(m_common.twoButtonMotorControl(m_operatorInput.getJoyButton(2), m_operatorInput.getJoyButton(3)));

    /**
     * SET Motor Power levels TO ZERO for DRIVE mode
     */
    m_mainMast.MastManualControl(0);
    m_gripper.setGripperPitchPower(0);
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
