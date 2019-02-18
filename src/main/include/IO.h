#pragma once

#include <iostream>
#include <string>
#include <frc/Talon.h>
#include "rotaryEncoderIO.h"

class motorIO {

public:

/*
method to check rotation and return it in radians
*/
double checkTalonRotation ();