/*
    Global Variables 
*/

//Initialize Variables at Zero so motors don't jump from errant memory values (they are easily spooked)
double xRefinedVel = 0;
double yRefinedVel = 0;
double zRefinedRot = 0;

//Limit Switches must be accessible by all classes
bool limSwitchStateArr[10];