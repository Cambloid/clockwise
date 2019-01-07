#pragma once

#include "Core/Image/ImageContainer.h"
#include "Core/DTO/FeatureContainer.h"

#include <opencv2/xfeatures2d.hpp>

class SIFTDetector
{
public:
    SIFTDetector();
    ~SIFTDetector();
    std::vector<FeatureContainer> StartDetection(std::vector<ImageContainer> &imageContainerList);

};
