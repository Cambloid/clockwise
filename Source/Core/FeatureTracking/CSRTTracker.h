#pragma once

#include <QList>
#include <QDebug>
#include <iostream>

#include "Core/Image/ImageContainer.h"
#include "Core/DTO/FeatureContainer.h"

#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/tracking.hpp>

class CSRTTracker
{

private:
    std::vector<ImageContainer> imageList;
    std::vector<FeatureContainer> featureContainerList;


public:
    CSRTTracker(std::vector<ImageContainer> &imageList, std::vector<FeatureContainer> &featureContainerList);

public:
    void StartTracking();
};
