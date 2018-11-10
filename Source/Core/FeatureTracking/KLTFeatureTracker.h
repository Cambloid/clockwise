#pragma once

#include <QList>
#include <iostream>

#include "Core/Image/ImageContainer.h"
#include "Core/DTO/FeatureContainer.h"

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"


struct SingleTrackResult {
    std::vector<uchar> status;
    std::vector<float> err;
};

class KLTFeatureTracker
{

private:
    QList<ImageContainer> imageList;
    QList<FeatureContainer> featureContainerList;


public:
    KLTFeatureTracker(QList<ImageContainer> &imageList, QList<FeatureContainer> &featureContainerList);

public:
    void StartTracking();
    SingleTrackResult TrackImagePair(ImageContainer prevImage, FeatureContainer prevImageFeatureContainer, ImageContainer image, FeatureContainer imageFeatureContainer);

};
