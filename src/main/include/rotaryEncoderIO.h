#include <frc/Encoder.h>
#include <iostream>

void resetTickerAll() {
    frontLeftEncoder.Reset();
    frontRightEncoder.Reset();
    backleftEncoder.Reset();
    backRightEncoder.Reset();
}

void resetTicker(frc::Encoder encoder) {
    encoder.Reset();
}

void setDistancePerPulse(frc::Encoder encoder, double distance) {
    encoder.SetDistancePerPulse(distance);
}

void setAllDistancePerPulse(double distance) {
    frontLeftEncoder.SetDistancePerPulse(distance);
    frontRightEncoder.SetDistancePerPulse(distance);
    backleftEncoder.SetDistancePerPulse(distance);
    backRightEncoder.SetDistancePerPulse(distance);
}

long long checkMotorRotations(frc::Encoder encoder) {
    encoder.GetDistance();
}

double getPulses (frc::Encoder encoder) {
    
}