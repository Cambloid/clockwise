#pragma once

#include <QList>

#include "Source/Core/Image/ImageContainer.h"
#include "Source/Core/DTO/FeatureContainer.h"

#include "Source/Core/DescriptorExtractor/SIFTDescriptorExtractor.h"
#include "Source/Core/DTO/SIFTDescriptorContainer.h"
#include "Source/Core/DTO/DMatchContainer.h"

#include "opencv2/opencv_modules.hpp"
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"



class FLANNMatcher
{
private:
    std::vector<ImageContainer> imageList;
    std::vector<SIFTDescriptorContainer> siftDescriptorContainer;

    std::vector<cv::DMatch> matchFeatures(cv::FlannBasedMatcher matcher, cv::Mat descriptor1, cv::Mat descriptor2);

public:
    FLANNMatcher(std::vector<ImageContainer> &imageList, std::vector<SIFTDescriptorContainer> &siftDescriptorContainerList);

public:
    std::vector<DMatchContainer> StartMatching();

};
