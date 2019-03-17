/**
 * Code for controlling the rise and fall of the main lifting mast.
 * Should have take data from OpsTeamIO and be able to hold the mast at a certain height using the rotary encoders
 */

#include "MainMast.h"
#include "MainMastConst.h"

MainMast::MainMast()
{
    //Initialize the Motor Controllers (Note: MainMastMotor MUST be a TalonSRX as it uses an encoder)
    this->m_pMainMastMotor = new TalonSRX(4);
    this->m_pMainMastMotorSlave = new TalonSRX(3);

    //Set 2nd Motor to slave to Primary Motor Controller
    this->m_pMainMastMotorSlave->Set(ControlMode::Follower, 4);
    //Enable Active Braking on the mast motor (reduces coasting)
    this->m_pMainMastMotor->SetNeutralMode(ctre::phoenix::motorcontrol::Brake);


}

MainMast::~MainMast() {}

/**
 * Eventually, this function will drop the mast to the bottom limit switch at low power,
 * then raise the mast to the bottom-most "running" position
 * It could also trip if a limit switch is hit unexpectedly
 */
void MainMast::MastHome()
{
    if (limSwitchStateArr[0]) {}
}

void MainMast::MainMastInit()
{
}

/**
 * You should probably deprecate this...
 */
void MainMast::MastTestInit()
{
    //Get Absolute sensor position, disregarding "turnovers"
    //int absolutePosition = this->m_pMainMastMotor->GetSelectedSensorPosition(0) & 0xFFF;
    //this->m_pMainMastMotor->SetSelectedSensorPosition(absolutePosition, kPIDLoopIdx, kTimeoutMs);

    /** Deprecated to test Motion Magic
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
    */
   
    //this->m_pMainMastMotor->ConfigFactoryDefault();
    
    //Configure the Sensor
    this->m_pMainMastMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);

    /* Zero the sensor */
    this->m_pMainMastMotor->SetSelectedSensorPosition(0, 0, 10);
    this->m_pMainMastMotor->SetSensorPhase(true);
    this->m_pMainMastMotor->SetInverted(false);


    //Set the control mode to Motion Magic. Passing Position 0 should neutralize the PID controller,
    //but kF (Feed Forward) will jump this and could cause an oscilation at LIMIT.
    //Instead, a homing function should be called
    this->m_pMainMastMotor->Set(ControlMode::MotionMagic, 0);

    //Pretty sure this syncs the Talon's update rate to the RIO's - some smart guy on YouTube said to do it
    this->m_pMainMastMotor->SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
    this->m_pMainMastMotor->SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);

    //Configure Nominal/Peak Power. (Hint: Use "Peak" to clamp PID's power for testing)
    this->m_pMainMastMotor->ConfigNominalOutputForward(0, 10);
    this->m_pMainMastMotor->ConfigNominalOutputReverse(0, 10);
    this->m_pMainMastMotor->ConfigPeakOutputForward(1, 10);
    this->m_pMainMastMotor->ConfigPeakOutputReverse(-1, 10);

    //Set PIDs - these are important
    this->m_pMainMastMotor->SelectProfileSlot(0, 0);
    this->m_pMainMastMotor->Config_kF(0, 0.0, 10);
    this->m_pMainMastMotor->Config_kP(0, 2.0, 10);
    this->m_pMainMastMotor->Config_kI(0, 0.01, 10);
    this->m_pMainMastMotor->Config_kD(0, 0.0, 10);
    //this->m_pMainMastMotor->Config_IntegralZone(0, 20, 10);
    this->m_pMainMastMotor->ConfigMaxIntegralAccumulator(0, 100, 10);

    //Max Travel Velocity of Motion Profile in counts per 100ms
    this->m_pMainMastMotor->ConfigMotionCruiseVelocity(150, 10);
    //Max Acceleration of Motion Profile in counts per 100ms per second
    this->m_pMainMastMotor->ConfigMotionAcceleration(150, 10);
}

/**
 * Experimental: Use the Talon's Position Hold feature
 * Pass a desired sensor position in encoder counts
 * Status: EXPERIMENTAL
 */
void MainMast::MastTest(double targetPos)
{
    this->m_pMainMastMotor->Set(ControlMode::MotionMagic, targetPos);
}

/**
 * A testing method to control output power to the MainMast Motor based on operator joystick input
 * (or any double you pass it, takes values form -1 to 1)
 */
void MainMast::MastManualControl(double targetPower)
{
    if (!limSwitchStateArr[0]) {
        this->m_pMainMastMotor->Set(ControlMode::PercentOutput, targetPower);
    }
    else
    {
        this->m_pMainMastMotor->Set(ControlMode::PercentOutput, 0);
    }
}


/**
 * Resets controllers to factory defaults - There's something in the manual about factory defaults 
 * only taking effect after rebooting a controller? Not sure, [Citation Required]
 */
void MainMast::nukeControllers()
{
    this->m_pMainMastMotor->ConfigFactoryDefault();
    this->m_pMainMastMotorSlave->ConfigFactoryDefault();
}

