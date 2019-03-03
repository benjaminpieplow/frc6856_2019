/**
 * Code for controlling the rise and fall of the main lifting mast.
 * Should have take data from OpsTeamIO and be able to hold the mast at a certain height using the rotary encoders
 */

#include "MainMast.h"
#include "MainMastConst.h"

MainMast::MainMast()
{
    //Initialize the Motor Controller (Note: MUST be a TalonSRX as it uses an encoder)
    this->m_pMainMastMotor = new TalonSRX(4);

    //Initialize an Array of DigitalInputs
    for (int i = 0; i < 10; i++)
    {
        this->m_pLimitSwitchObjects[i] = new frc::DigitalInput(i);
    }

}

MainMast::~MainMast() {}

/**
 * Eventually, this function will drop the mast to the bottom limit switch at low power, then raise the mast to the bottom-most "running" position
 * It could also trip if a limit switch is hit unexpectedly
 */
void MainMast::MastHome()
{
    if (this->m_pLimitSwitchState[0]) {}
}

void MainMast::MainMastInit()
{
    //Enable Active Braking on the mast motor (reduces coasting)
    this->m_pMainMastMotor->SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
}

/**
 * You should probably deprecate this...
 */
void MainMast::MastTestInit()
{
    //Get Absolute sensor position, disregarding "turnovers"
    //int absolutePosition = this->m_pMainMastMotor->GetSelectedSensorPosition(0) & 0xFFF;
    //this->m_pMainMastMotor->SetSelectedSensorPosition(absolutePosition, kPIDLoopIdx, kTimeoutMs);

    this->m_pMainMastMotor->Set(ControlMode::Position, 0);

    this->m_pMainMastMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, kPIDLoopIdx, kTimeoutMs);
    this->m_pMainMastMotor->SetSelectedSensorPosition(0, kPIDLoopIdx, kTimeoutMs);
    this->m_pMainMastMotor->SetSensorPhase(true);
    this->m_pMainMastMotor->SetInverted(ctre::phoenix::motorcontrol::InvertType::None);

    this->m_pMainMastMotor->ConfigNominalOutputForward(0, kTimeoutMs);
    this->m_pMainMastMotor->ConfigNominalOutputReverse(0, kTimeoutMs);
    this->m_pMainMastMotor->ConfigPeakOutputForward(0.25, kTimeoutMs);
    this->m_pMainMastMotor->ConfigPeakOutputReverse(-0.25, kTimeoutMs);

    this->m_pMainMastMotor->Config_kP(0, 15, kTimeoutMs);
    this->m_pMainMastMotor->Config_kI(0, 0.0, kTimeoutMs);
    this->m_pMainMastMotor->Config_kD(0, 0.0, kTimeoutMs);
    //this->m_pMainMastMotor->ConfigAllowableClosedloopError(0, 10, kTimeoutMs);

    this->m_pMainMastMotor->ConfigNeutralDeadband(0, kTimeoutMs);
}

/**
 * Experimental: Use the Talon's Position Hold feature
 * Status: FAIL
 */
void MainMast::MastTest(double targetPos)
{
    this->m_pMainMastMotor->Set(ControlMode::Position, targetPos);
    //this->m_pMainMastMotor->Set(ControlMode::Velocity, targetPos);

    //Set the talon to hold
    //this->m_pMainMastMotor->Set(ControlMode::MotionProfile, );
}

/**
 * A testing method to control output power to the MainMast Motor based on operator joystick input (or any double you pass it)
 */
void MainMast::MastManualControl(double targetPower)
{
    if (this->m_pLimitSwitchState[2]) {
        this->m_pMainMastMotor->Set(ControlMode::PercentOutput, targetPower);
    }
    else
    {
        this->m_pMainMastMotor->Set(ControlMode::PercentOutput, 0);
    }
}

/**
 * Returns TRUE when the BOTTOM limit switch is pressed
*/

/**
 * Cycles through all limit switches and puts their states into an array
 */
void MainMast::updateLimitSwitches()
{
    for (int i = 0; i < 9; i++)
    {
        this->m_pLimitSwitchState[i] = this->m_pLimitSwitchObjects[i]->Get();
    }
}

/**
 * For getting independant limit switches outside of the MainMast object
 */
bool MainMast::getLimitSwitch(int limIndex)
{
    return this->m_pLimitSwitchState[limIndex];
}