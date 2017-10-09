#ifndef BACKGROUNDSUBTRACTION_H
#define BACKGROUNDSUBTRACTION_H

#include <opencv2/opencv.hpp>


using namespace cv;

class BackgroundSubtraction
{
private:
    Ptr<BackgroundSubtractor> bg_model; // MOG Background subtractor
    Ptr<BackgroundSubtractor> bg_model2; // MOG2 Background subtractor
    Ptr< BackgroundSubtractor> pGMG; // GMG Background subtractor
    Ptr< BackgroundSubtractor> pKNN; // KNN Background subtractor
public:
    BackgroundSubtraction();
     BackgroundSubtraction(int option);
    Mat* applyMOG(Mat& frame, Mat& fgMaskMOG);
    Mat applyMOG2(Mat frame,Mat fgMaskMOG2);
    Mat applyGMG(Mat frame,Mat fgMaskGMG);
    Mat applyKNN(Mat frame,Mat fgMaskKNN);


};

#endif // BACKGROUNDSUBTRACTION_H
