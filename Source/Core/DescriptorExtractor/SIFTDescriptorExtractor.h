#pragma once

#include <vector>
#include <QList>

#include "Core/Image/ImageContainer.h"
#include "Core/DTO/FeatureContainer.h"

#include "Core/DTO/SIFTDescriptorContainer.h"

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

    QList<SIFTDescriptorContainer> StartExtraction(QList<ImageContainer> &imgContainerList, QList<FeatureContainer> &featureContainerList);
};
