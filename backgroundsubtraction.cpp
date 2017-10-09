#include "backgroundsubtraction.h"
// Opencv
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include "opencv2/bgsegm.hpp"
#include <opencv2/opencv.hpp>

#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;


BackgroundSubtraction::BackgroundSubtraction()
{
    bg_model = bgsegm::createBackgroundSubtractorMOG();
    bg_model2 = createBackgroundSubtractorMOG2();
    pGMG = bgsegm::createBackgroundSubtractorGMG();
    pKNN = createBackgroundSubtractorKNN();
}


/* Constructor with an argument
 * 0 = Subtractor MOG
 * 1 = Subtractor MOG2
 * 2 = Subtractor GMG
 * 3 = Subtractor KNN
*/
BackgroundSubtraction::BackgroundSubtraction(int option){
    switch (option) {
    case 0:
        bg_model= bgsegm::createBackgroundSubtractorMOG();
        break;
    case 1:
        bg_model2= createBackgroundSubtractorMOG2();
        break;
    case 2:
        pGMG = bgsegm::createBackgroundSubtractorGMG();
        break;
    case 3:
        pKNN = createBackgroundSubtractorKNN();
        break;
        cout<<"Option no valid"<<endl;
        break;
    }
}


Mat* BackgroundSubtraction::applyMOG(Mat& frame, Mat& fgMaskMOG){
    bg_model = bgsegm::createBackgroundSubtractorMOG();
    bg_model->apply(frame, fgMaskMOG);
    return &fgMaskMOG;
}

Mat BackgroundSubtraction::applyMOG2(Mat frame, Mat fgMaskMOG2){

    bg_model2->apply(frame, fgMaskMOG2);
    return fgMaskMOG2;
}

Mat BackgroundSubtraction::applyGMG(Mat frame, Mat fgMaskGMG){
    pGMG = bgsegm::createBackgroundSubtractorGMG();
    pGMG ->apply(frame, fgMaskGMG);
    return fgMaskGMG;
}

 Mat BackgroundSubtraction::applyKNN(Mat frame, Mat fgMaskKNN){
     pKNN = createBackgroundSubtractorKNN();
     pKNN->apply(frame, fgMaskKNN);
     return fgMaskKNN;
 }
