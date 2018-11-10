#pragma once

#include <QList>

#include "Core/Image/ImageContainer.h"
#include "Core/DTO/FeatureContainer.h"

#include "Core/DescriptorExtractor/SIFTDescriptorExtractor.h"
#include "Core/DTO/SIFTDescriptorContainer.h"
#include "Core/DTO/DMatchContainer.h"

#include "opencv2/opencv_modules.hpp"
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"



class FLANNMatcher
{
private:
    QList<ImageContainer> imageList;
    QList<SIFTDescriptorContainer> siftDescriptorContainer;

    std::vector<cv::DMatch> matchFeatures(cv::FlannBasedMatcher matcher, cv::Mat descriptor1, cv::Mat descriptor2);

public:
    FLANNMatcher(QList<ImageContainer> &imageList, QList<SIFTDescriptorContainer> &siftDescriptorContainerList);

public:
    std::vector<DMatchContainer> StartMatching();

};
