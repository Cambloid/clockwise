#pragma once

#include <vector>
#include <QList>

#include "Source/Core/Image/ImageContainer.h"
#include "Source/Core/DTO/FeatureContainer.h"

#include "Source/Core/DTO/SIFTDescriptorContainer.h"

#include <opencv2/core.hpp>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class SIFTDescriptorExtractor
{
public:
    SIFTDescriptorExtractor();

    std::vector<SIFTDescriptorContainer> StartExtraction(std::vector<ImageContainer> &imgContainerList, std::vector<FeatureContainer> &featureContainerList);
};
