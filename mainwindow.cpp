#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;
using namespace cv;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

      ui->setupUi(this);

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
            imshow("edges", edges);
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
