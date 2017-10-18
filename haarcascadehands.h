#ifndef HAARCASCADEHANDS_H
#define HAARCASCADEHANDS_H

#include <opencv2/opencv.hpp>

using namespace cv;

class HaarCascadeHands
{
public:
    HaarCascadeHands();
    void processHaarHandsClassifier();

private:
    Mat *img;
    CascadeClassifier cascade;
    CvMemStorage *cstorage;
    CvMemStorage *hstorage;
    String hand_cascade_name;
    int key;
    void detectHands(Mat *img);
};

#endif // HAARCASCADEHANDS_H
