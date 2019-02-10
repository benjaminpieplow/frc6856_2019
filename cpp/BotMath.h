#pragma once
#include <math.h>
#include <iostream>

namespace BotMath {

//MAKING VARIABLES 
const double wheelAngle[4] = {45, 135, 225, 315};
const float botWheelBaseRadius [4] = {18.56, 18.56, 18.56, 18.56,}; //Subject to change by frame design; inches;
float desiredYVelocity;
float desiredXVelocity;
float desiredZRVelocity;
double desiredWheelVelocity[4];



//doing math for each wheel (wheel no is the loop counter)
static void getDesiredWheelVelocity () {
    for (int ctr = 0; ctr < 3; ctr++) {
        desiredWheelVelocity[ctr] = -(sin(wheelAngle[ctr]) * desiredYVelocity) - (cos(wheelAngle[ctr]) * desiredYVelocity);
    }

}

}