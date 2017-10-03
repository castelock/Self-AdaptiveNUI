// UI
#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <opencv2/core/core.hpp>
//#include <opencv2/opencv.hpp>
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/videoio.hpp"
//#include <opencv2/video.hpp>
//#include <iostream>

// Opencv
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>


#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

      ui->setupUi(this);

       Ptr<BackgroundSubtractor> bg_model;

      //Messages for the label
      QString infoCamera = "Camera Status";
      QString cameraWorking = "Camera is working";
      QString cameraNotWorking = "Camera is not working";

      //Quit the app
      connect(ui->btQuit, &QPushButton::clicked,this,&QMainWindow::close);

    // Inform about the status of the camera
    ui->lbCameraInfo->setText(infoCamera);

    // Init background substractor
   bg_model = createBackgroundSubtractorMOG2();

    //Getting frames from the camera
    VideoCapture cap(0); // open the default camera

        if(!cap.isOpened())  // check if we succeeded
            ui->lbCameraInfo->setText(cameraNotWorking);
        else
        ui->lbCameraInfo->setText(cameraWorking);

        Mat edges;
        for(;;)
        {
            Mat frame;
            cap >> frame; // get a new frame from camera
            cvtColor(frame, edges, COLOR_BGR2Lab);
            imshow("Lab Color", edges);
            if(waitKey(30) >= 0) break;
        }

//    Mat inputImage = imread("/home/acg/Pictures/acglogo.png");
//    if(!inputImage.empty()) imshow("Display Image", inputImage);
//    waitKey();


}

MainWindow::~MainWindow()
{
    delete ui;
}
