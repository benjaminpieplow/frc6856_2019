/**
 * Control of the main mast system
 * Currently overflowing with "hot standby" code to support an "agile" development environment
 * Please don't delete or comment out unused methods, they won't hurt anyone!
 */

#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motion/TrajectoryPoint.h>
#include "Pneumatics.h"
#include "GlobalVars.h"
#include "RobotIO.h"

class MainMast
{
    public:
    MainMast();
    ~MainMast();

    void MainMastInit();

    //Loweres the mast until it hits the lower limit switch
    void MastHome();

    void MastTestInit();

    void MastTest(double targotPos);

    void MastManualControl(double targetPower);

    void nukeControllers();

    private:
    //Mast Motor Controllers
    TalonSRX* m_pMainMastMotor;
    TalonSRX* m_pMainMastMotorSlave;

    //Mast Homing/Limit Switches
    frc::DigitalInput* m_pLimitSwitchObjects[10];

    //Pneumatic Brake for Mast
    //PneumaticActuator* m_pBrakePneumatic;

    //PWM Pin for Servo Brake
    //frc::PWM* m_pBrakeServo;

    /**
     * Track which stage of a mast flight maneuver the robot is in (if we use that)
     * 0 = HALT/E-STOP (motor coast/rest, brake off)
     * 1 = HOLD (motor brake, brake on)
     * 2 = CRUISE (motor 100% up)
     * 3 = FLYOVER (target limit switch is pressed but motor is not disabled)
     * 4 = APPROACH (target limit has been released, motor power is reversed and reduced)
     * 5 = LOCK (On target, set holding power/apply brake)
     * 6 = FLYUNDER (overshot target, motor 50% up)
     */
    int m_pFlightStage;

};