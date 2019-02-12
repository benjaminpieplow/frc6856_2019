#pragma once
/*

CAMERA PROGRAMMING, INCLUDES INIT, STREAMING, AND SETTING RES

*/
#include <iostream>
#include <frc/WPILib.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "cscore.h"
#include <sstream>
#include <cameraserver/CameraServer.h>

//INITITATES / CONNECTS THE CAMERAS TO THE RIO, IF NO VALUES ARE SPECIFIED, DEFUALT CONSTRUCOTR WILL BE USED

// namespace botVideo
namespace botVideo
{
//STREAMS THE CAMERA(S) TO THE DRIVER STATION
void StreamBotCameras(int resWidth, int res_height, int fps)
{
    //defining camera, adds name and USB port
    cs::UsbCamera frontCamera{"camera1", 0};
    frontCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture();

    //setting res
    frontCamera.SetResolution(resWidth, res_height);
    //setting frames per second
    frontCamera.SetFPS(fps);

    //creating sink to display vid
    cs::CvSink frontCameraSink = frc::CameraServer::GetInstance()->GetVideo();

    //creating stream to output video to be outputted to driver station
    cs::CvSource vidStream = frc::CameraServer::GetInstance()->PutVideo("Gray", resWidth, res_height);
    frontCameraSink.SetSource(frontCamera);

    //making mat array (images that are written in arrays)
    cv::Mat source;
    cv::Mat output;
    
    //telling drivers, cameras are online
    std::cout << "Camera Online";
    //displaying video to driver station
    while (true)
    {
        frontCameraSink.GrabFrame(source);
        cvtColor(source, output, cv::COLOR_BGR2GRAY);
        vidStream.PutFrame(source);
    }
}

//SECOND CONSTRUCTOR | USES DEFAULT VALUES
void StreamBotCameras()
{
    //defining camera, adds name and USB port
    cs::UsbCamera frontCamera{"camera1", 0};
    frontCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture();

    //setting res
    frontCamera.SetResolution(640, 480);
    //setting frames per second
    frontCamera.SetFPS(15);

    //creating sink to display vid
    cs::CvSink frontCameraSink = frc::CameraServer::GetInstance()->GetVideo();

    //creating stream to output video to be outputted to driver station
    cs::CvSource vidStream = frc::CameraServer::GetInstance()->PutVideo("Gray", 640, 480);
    frontCameraSink.SetSource(frontCamera);

    //making mat array (images that are written in arrays)
    cv::Mat source;
    cv::Mat output;

    //telling drivers cameras are online
    std::cout << "Camera Online";
    
    //displaying video to driver station
    while (true)
    {
        frontCameraSink.GrabFrame(source);
        cvtColor(source, output, cv::COLOR_BGR2GRAY);
        vidStream.PutFrame(source);
    }
}

} // namespace botVideo