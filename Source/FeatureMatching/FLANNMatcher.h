#pragma once

#include <QList>
#include "Image/ImageContainer.h"
#include "DTO/FeatureContainer.h"

#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/xfeatures2d.hpp"

class FLANNMatcher
{
private:
    QList<ImageContainer> imageList;
    QList<FeatureContainer> featureContainerList;

public:
    FLANNMatcher(QList<ImageContainer> &imageList, QList<FeatureContainer> &featureContainerList);

public:
    void StartMatching();

};
