#include "haarcascadehands.h"

// Opencv
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

HaarCascadeHands::HaarCascadeHands()
{
    img = 0;
    hand_cascade_path = "../Haar_Cascade_Hands/haarcascade_hand_1.xml";

}

void HaarCascadeHands::processHaarHandsClassifier(Mat *img){
//    int px;
//    int py;
    int edge_thresh = 1;
    // Rects to detect the hands
    vector<Rect> hands;

//    Mat *gray = cvCreateImage( cvSize(img->cols,img->rows), 8, 1);
//    Mat *edge = cvCreateImage( cvSize(img->width,img->height), 8, 1);

    Mat gray(img->rows, img->cols, CV_8UC3, Scalar(0,0,0));
    Mat edge(img->rows, img->cols, CV_8UC3, Scalar(0,0,0));

    cvtColor(*img,gray,CV_BGR2GRAY);

    // Only for Iplimage
    //gray->origin=1;

    threshold(gray,gray,100,255, THRESH_BINARY);

    //cvSmooth(gray, gray, CV_GAUSSIAN, 11, 11);
    GaussianBlur(gray, gray, Size(11, 11),0,0);

   // cvCanny(gray, edge, (float)edge_thresh, (float)edge_thresh*3, 5);
    Canny(gray,edge,edge_thresh, edge_thresh*3, 5);

   // CvSeq *hand = cvHaarDetectObjects(img, cascade, hstorage, 1.2, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(100, 100));



//    CvRect *r = ( CvRect* )cvGetSeqElem( hand, 0 );
//    cvRectangle( img,
//        cvPoint( r->x, r->y ),
//        cvPoint( r->x + r->width, r->y + r->height ),
//        CV_RGB( 255, 0, 0 ), 1, 8, 0 );

//    imshow("ImgCa

    if(cascade.load(hand_cascade_path)){
        cascade.detectMultiScale(*img,hands, 1.2, 2, CV_HAAR_DO_CANNY_PRUNING, Size(100,100), Size(100,100));

        for (int i = 0; i < hands.size(); i++) {
            Rect r = hands[i];
            printf("A hand is found at Rect(%d,%d,%d,%d).\n", r.x, r.y, r.width, r.height);
        }
    }

}





