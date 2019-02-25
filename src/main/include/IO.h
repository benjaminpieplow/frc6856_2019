#pragma once

#include "rotaryEncoderIO.h"

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
};