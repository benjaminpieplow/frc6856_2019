#pragma once

#include "rotaryEncoderIO.h"

//This class for only the drivetrain as it is built on that | DO NOT use for any other motors, use the "motorIO" class for them
class driveMotorIO {

public:
//CHECKS THE THE AMOUNT OF ROTATIONS since reset 
long long checkMotorRotations();
//SETS THE COUNT TO ZERO ON ALL ENCODERS
void resetTickerAll();
//Sets the passed encoder's count to zero
void resetTicker(frc::Encoder encoder);
//sets the distance per square pulse
void setDistancePerPulse(frc::Encoder encoder, double distance);
//sets all the drives Motors per pulse
void setAllDistancePerPulse(double distance);
//gets the amount of pulses sent since reset
double getPulses(frc::Encoder encoder);
};

class MotorIO {

};