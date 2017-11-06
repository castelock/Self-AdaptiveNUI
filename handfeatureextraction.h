#ifndef HANDFEATUREEXTRACTION_H
#define HANDFEATUREEXTRACTION_H

#include <opencv2/opencv.hpp>
//Background Subtractor
#include "backgroundsubtraction.h"


class HandFeatureExtraction
{
private:
    std::vector<cv::KeyPoint> keypoints_1;
    cv::Mat img_keypoints_1;
    cv::Mat fgMaskMOG2;
    BackgroundSubtraction *bs;

public:
    HandFeatureExtraction();
    void sift(cv::Mat frame);
    void sift_BS(cv::Mat frame);
};

#endif // HANDFEATUREEXTRACTION_H
