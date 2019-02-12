#pragma once
/*

CAMERA PROGRAMMING, INCLUDES INIT, STREAMING, AND SETTING RES

*/
#include <iostream>
#include "cscore.h"

//INITITATES / CONNECTS THE CAMERAS TO THE RIO, IF NO VALUES ARE SPECIFIED, DEFUALT CONSTRUCOTR WILL BE USED

// namespace botVideo
namespace botVideo
{
//STREAMS THE CAMERA(S) TO THE DRIVER STATION
void StreamBotCameras(int resWidth, int res_height, int fps)
{
    static cs::UsbCamera frontCamera{"camera1", 0};
    frontCamera.SetResolution(resWidth, res_height);
    frontCamera.SetFPS(fps);
}
//SECOND CONSTRUCTOR | USES DEFUALT VALUES
void StreamBotCameras()
{
    //defining camera, adds name and USB port
    static cs::UsbCamera frontCamera{"camera1", 0};
    //setting res
    frontCamera.SetResolution(640, 480);
    //setting frames per second
    frontCamera.SetFPS(15);
}

} // namespace botVideo