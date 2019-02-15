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
void StreamBotCameras(int resWidth, int resHeight, int fps)
{
   //instantiaing CS_Core USB camera
    cs::UsbCamera mainCamera;
    //setting res
    mainCamera.SetResolution(resWidth, resHeight);
    //setting fps
    mainCamera.SetFPS(fps);
    //streaming camera...hopefully to dashboard
    mainCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
}

//SECOND CONSTRUCTOR | USES DEFAULT VALUES
void StreamBotCameras()
{
    //instantiaing CS_Core USB camera
    cs::UsbCamera mainCamera;
    //setting res
    mainCamera.SetResolution(320, 240);
    //setting fps
    mainCamera.SetFPS(15);
    //streaming camera...hopefully to dashboard
    mainCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
}

/*
just ignore this method, just a little project, I am just trying to do some video processing (with as little overhead as possible)
*/
double checkSimularityToOrgin()
{

    /*
    cs::UsbCamera camera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
    //setting resolution
        camera.SetResolution(640, 480);
        //creating image (video sink)
        cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo();
        cs::CvSource outputStreamStd = frc::CameraServer::GetInstance()->PutVideo("Gray", resWidth, resHeight);

        //creating image matrixes
        cv::Mat source;
        cv::Mat output;

        while(true) {
            cvSink.GrabFrame(source);
            cvtColor(source, output, cv::COLOR_BGR2GRAY);
            outputStreamStd.PutFrame(output);
        }
   */
}

} // namespace botVideo