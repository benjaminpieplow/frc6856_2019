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
    //defining camera, adds name and USB port
    static cs::UsbCamera frontCamera{"camera1", 0};
    //setting res
    frontCamera.SetResolution(resWidth, res_height);
    //setting frames per second
    frontCamera.SetFPS(fps);

    //setting video mode for streaming
    frontCamera.SetVideoMode(cs::VideoMode::kMJPEG, resWidth, res_height, fps);

    //creating sink to display vid
    cs::VideoSink frontCameraSink{};
    frontCameraSink.SetSource(frontCamera);

    
}
//SECOND CONSTRUCTOR | USES DEFAULT VALUES
void StreamBotCameras()
{
    //defining camera, adds name and USB port
    static cs::UsbCamera frontCamera{"camera1", 0};
    //setting res
    frontCamera.SetResolution(640, 480);
    //setting frames per second
    frontCamera.SetFPS(15);

    //setting video mode for streaming
    frontCamera.SetVideoMode(cs::VideoMode::kMJPEG, 640, 480, 15);

    //creating sink to display vid
    cs::VideoSink frontCameraSink{};
    frontCameraSink.SetSource(frontCamera);
}

} // namespace botVideo