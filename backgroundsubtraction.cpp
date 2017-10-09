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

}


Mat BackgroundSubtraction::applyMOG(Mat frame, Mat fgMaskMOG){
    bg_model = bgsegm::createBackgroundSubtractorMOG();
    bg_model->apply(frame, fgMaskMOG);
    return fgMaskMOG;
}

Mat BackgroundSubtraction::applyMOG2(Mat frame, Mat fgMaskMOG2){
    bg_model2= createBackgroundSubtractorMOG2();
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
