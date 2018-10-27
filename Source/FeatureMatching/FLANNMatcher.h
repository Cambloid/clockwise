#pragma once

#include <QList>

#include "Image/ImageContainer.h"
#include "DTO/FeatureContainer.h"

#include "DescriptorExtractor/SIFTDescriptorExtractor.h"
#include "DTO/SIFTDescriptorContainer.h"
#include "DTO/DMatchContainer.h"

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
    FLANNMatcher(QList<ImageContainer> &imageList, QList<SIFTDescriptorContainer> &siftFeatureContainer);

public:
    std::vector<DMatchContainer> StartMatching();

};
