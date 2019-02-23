/**
 * Code for controlling the rise and fall of the main lifting mast.
 * Should have take data from OpsTeamIO and be able to hold the mast at a certain height using the rotary encoders
 */

#include "MainMast.h"
#include "MainMastConst.h"

MainMast::MainMast()
{
    //Initialize the Motor Controller (Note: MUST be a TalonSRX as it uses an encoder)
    this->m_pMainMastMotor = new TalonSRX(20);

    //Initialize the "Bottom" homing switch
    this->m_pLimitSwitchLower = new frc::DigitalInput(0);
    //Initialize the "Top" homing switch
    this->m_pLimitSwitchUpper = new frc::DigitalInput(1);
}

MainMast::~MainMast() {}

void MainMast::MastHome() {}

void MainMast::MastTestInit()
{
    //Get Absolute sensor position, disregarding "turnovers"
    //int absolutePosition = this->m_pMainMastMotor->GetSelectedSensorPosition(0) & 0xFFF;
    //this->m_pMainMastMotor->SetSelectedSensorPosition(absolutePosition, kPIDLoopIdx, kTimeoutMs);

    this->m_pMainMastMotor->SetSelectedSensorPosition(0, kPIDLoopIdx, kTimeoutMs);
    this->m_pMainMastMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, kPIDLoopIdx, kTimeoutMs);
    this->m_pMainMastMotor->SetSensorPhase(true);

    this->m_pMainMastMotor->ConfigNominalOutputForward(0, kTimeoutMs);
    this->m_pMainMastMotor->ConfigNominalOutputReverse(0, kTimeoutMs);
    this->m_pMainMastMotor->ConfigPeakOutputForward(0.25, kTimeoutMs);
    this->m_pMainMastMotor->ConfigPeakOutputReverse(0.25, kTimeoutMs);

    this->m_pMainMastMotor->Config_kP(0, 100);
    this->m_pMainMastMotor->Config_kI(0, 0.1);
    this->m_pMainMastMotor->Config_kD(0, 0.0);
    this->m_pMainMastMotor->ConfigAllowableClosedloopError(0, 10, kTimeoutMs);

    this->m_pMainMastMotor->ConfigNeutralDeadband(0, kTimeoutMs);
}

void MainMast::MastTest(int targetPos)
{
    this->m_pMainMastMotor->Set(ControlMode::Position, targetPos);
}