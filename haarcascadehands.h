#ifndef HAARCASCADEHANDS_H
#define HAARCASCADEHANDS_H

#include <opencv2/opencv.hpp>

//#include "tools.h"

class HaarCascadeHands
{
public:
    HaarCascadeHands();
    void processHaarHandsClassifier(cv::Mat *img, int& cont);

private:
   cv :: Mat *img;
    cv::CascadeClassifier cascade;
    CvMemStorage *cstorage;
    CvMemStorage *hstorage;
   std:: string hand_cascade_path;
    int key;
   // Tools *tool;
    //void detectHands(Mat *img);
};

#endif // HAARCASCADEHANDS_H
