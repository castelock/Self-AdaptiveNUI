#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cv::Mat inputImage = cv::imread("/home/acg/Pictures/acglogo.png");
    if(!inputImage.empty()) cv::imshow("Display Image", inputImage);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
