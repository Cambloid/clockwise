#pragma once

#include "Core/Image/ImageContainer.h"
#include "Core/DTO/FeatureContainer.h"

#include <opencv2/features2d.hpp>
#include <QList>
#include <QDebug>

class ORBDetector
{
private:
    int numFeatures = 10;

public:
    ORBDetector();
    ~ORBDetector();
    std::vector<FeatureContainer> StartDetection(std::vector<ImageContainer> &imageContainerList);


    int getNumFeatures() const;
    void setNumFeatures(int value);
};
