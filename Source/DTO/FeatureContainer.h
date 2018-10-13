#pragma once

#include "Image/ImageContainer.h"

#include <vector>
#include <opencv2/core.hpp>

struct FeatureContainer 
{
    std::vector<cv::KeyPoint> keyPointList;

    FeatureContainer(std::vector<cv::KeyPoint> keyPointList) {
        this->keyPointList = keyPointList;
    }

};
