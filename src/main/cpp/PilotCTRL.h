#include <frc/Joystick.h>

//Raw Values from Joystick (-1 to 1, 0 at rest)
static double xAnalogVel = 0;
static double yAnalogVel = 0;
static double zAnalogRot = 0;
//Refined Raw Values
static double xRefinedVel = 0;
static double yRefinedVel = 0;
static double zRefinedRot = 0;

class CTRLInput {
    public:


    //Cal to input data from controllers
    void getController() {
        xAnalogVel = primaryJoy.GetRawAxis(0);
        yAnalogVel = primaryJoy.GetRawAxis(1);
        zAnalogRot = primaryJoy.GetRawAxis(4);
        refineInput();
    }

    //Refine Input. Current use: Dampen power. Future use: convert to meters/second
    void refineInput() {
        const double modifier = 0.3;
        xRefinedVel = xAnalogVel * modifier;
        yRefinedVel = yAnalogVel * modifier;
        zRefinedRot = zAnalogRot * modifier;
    }

    private:
    frc::Joystick primaryJoy{0};

}