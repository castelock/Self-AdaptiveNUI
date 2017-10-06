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
#include "opencv2/core/cuda.hpp"
//#include "opencv2/video/background_segm.hpp"
#include "opencv2/bgsegm.hpp"
#include <opencv2/opencv.hpp>



#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);

      //Variables
      Ptr<BackgroundSubtractor> bg_model;
      Ptr<BackgroundSubtractor> bg_model2;
      Mat edges;
      Mat fgMask;
      Mat fgMask2;
       Mat frame;


      //Messages for the label
      QString infoCamera = "Camera Status";
      QString cameraWorking = "Camera is working";
      QString cameraNotWorking = "Camera is not working";

      //Quit the app
      connect(ui->btQuit, &QPushButton::clicked,this,&QMainWindow::close);

    // Inform about the status of the camera
    ui->lbCameraInfo->setText(infoCamera);

    // Init background substractor
    bg_model = bgsegm::createBackgroundSubtractorMOG();
    bg_model2 = createBackgroundSubtractorMOG2();

    //Getting frames from the camera
    VideoCapture cap(0); // open the default camera

        if(!cap.isOpened())  // check if we succeeded
            ui->lbCameraInfo->setText(cameraNotWorking);
        else
        ui->lbCameraInfo->setText(cameraWorking);


        for(;;)
        {

            cap >> frame; // get a new frame from camera
            cvtColor(frame, edges, COLOR_BGR2Lab);
            //imshow("Lab Color", edges);
            if(waitKey(30) >= 0) break;
        }

        bg_model -> apply(frame, fgMask);
        bg_model2 -> apply(frame,fgMask2);

        imshow("Frame",frame);
        imshow("FGMask MOG",fgMask);
        imshow("FGMask MOG 2",fgMask2);

//    Mat inputImage = imread("/home/acg/Pictures/acglogo.png");
//    if(!inputImage.empty()) imshow("Display Image", inputImage);
//    waitKey();


}

MainWindow::~MainWindow()
{
    delete ui;
}
