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
#include "opencv2/bgsegm.hpp"
#include <opencv2/opencv.hpp>

// SIFT library
#include "opencv2/xfeatures2d.hpp"

//#include <dlib/image_processing.h>
//#include <dlib/data_io.h>
//#include <dlib/image_processing/frontal_face_detector.h>

#include <iostream>
#include <sstream>

#include "backgroundsubtraction.h"

// using namespace dlib;
using namespace std;
using namespace cv;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

 //dlib::array<array2d<unsigned char> > images_train, images_test;
//    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();


      //Variables
    // Creating the object Background Subtraction
    BackgroundSubtraction* bs = new BackgroundSubtraction();
    Mat edges;
    Mat fgMask;
    Mat fgMaskMOG; // fg mask generated by MOG method
    Mat fgMaskMOG2; // fg mask generated by MOG2 method
    Mat fgMaskGMG; // fg mask generated by GMG method
    Mat fgMaskKNN; // fg mask generated by KNN method
    Mat resizeF;

    // SIFT UNDER REVISION
    Ptr<SIFT> sift = cv::xfeatures2d::SIFT::create(...);
    sift->detect(...);


      //Messages for the label
      QString infoCamera = "Camera Status";
      QString cameraWorking = "Camera is working";
      QString cameraNotWorking = "Camera is not working";

      //Quit the app
        connect(ui->btQuit, &QPushButton::clicked,this,&QMainWindow::close);


    // Inform about the status of the camera
    ui->lbCameraInfo->setText(infoCamera);



    //Getting frames from the camera
    VideoCapture cap(0); // open the default camera

//        if(!cap.isOpened())  // check if we succeeded
//            ui->lbCameraInfo->setText(cameraNotWorking);
//        else
//        ui->lbCameraInfo->setText(cameraWorking);


        for(;;)
        {
            Mat frame;
            cap >> frame; // get a new frame from camera

            fgMaskMOG2 = bs -> applyMOG2(frame,fgMaskMOG2);
            //cvtColor(frame, edges, COLOR_BGR2Lab);
            //imshow("Lab Color", edges);
            //            imshow("Frame",frame);

                        imshow("FGMask MOG 2",fgMaskMOG2);


            if(waitKey(10) == 27) break;
        }



}



MainWindow::~MainWindow()
{
    delete ui;
}
