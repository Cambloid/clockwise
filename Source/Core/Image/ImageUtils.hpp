#pragma once

#include <QList>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "Source/Core/DTO/FeatureContainer.h"

class ImageUtils {

public:
    static cv::Mat DrawKeypointFeatures(ImageContainer image, FeatureContainer featureContainer) {
        cv::Mat tmpImage = image.getImage().clone();
        for(int i = 0; i < featureContainer.keyPointList.size(); i++ ) {
            circle(tmpImage, featureContainer.keyPointList[i].pt, 3, cv::Scalar(255, 255, 255), 2, 8, 0);
        }
        return tmpImage;
    }

};
