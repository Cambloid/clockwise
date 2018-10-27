#pragma once

#include "Image/ImageContainer.h"

#include <QList>
#include <opencv2/core.hpp>

struct FeatureContainer 
{
    std::vector<cv::KeyPoint> keyPointList;

    FeatureContainer() {}

    FeatureContainer(std::vector<cv::KeyPoint> keyPointList) {
        this->keyPointList = keyPointList;
    }

};
