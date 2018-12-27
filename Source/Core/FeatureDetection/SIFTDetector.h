#pragma once

#include "Source/Core/Image/ImageContainer.h"
#include "Source/Core/DTO/FeatureContainer.h"

#include <opencv2/xfeatures2d.hpp>

class SIFTDetector
{
public:
    SIFTDetector();
    ~SIFTDetector();
    std::vector<FeatureContainer> StartDetection(std::vector<ImageContainer> &imageContainerList);

};
