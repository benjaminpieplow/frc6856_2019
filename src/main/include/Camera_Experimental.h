/*
just ignore this method, just a little project, I am just trying to do some video processing (with as little overhead as possible)

double checkSimularityToOrgin()
{

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
}
*/