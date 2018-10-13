#pragma once

#include "Image/ImageContainer.h"
#include "DTO/FeatureContainer.h"

#include <opencv2/xfeatures2d.hpp>

class SIFTDetector
{
public:
    SIFTDetector();
    ~SIFTDetector();
    QList<FeatureContainer> StartDetection(QList<ImageContainer> &imageContainerList);

};
