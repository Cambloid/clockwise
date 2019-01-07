#pragma once

#include "Core/Image/ImageContainer.h"

#include <QList>
#include <opencv2/core.hpp>

struct FeatureContainer 
{
    std::vector<cv::KeyPoint> keyPointList;
    std::vector<cv::Point2f> keyPointListPoint2f;

    FeatureContainer() {}

    FeatureContainer(std::vector<cv::KeyPoint> keyPointList) {
        this->keyPointList = keyPointList;
        for(int i = 0; i < keyPointList.size(); i++) {
            keyPointListPoint2f.push_back(keyPointList.at(i).pt);
        }
    }

};
