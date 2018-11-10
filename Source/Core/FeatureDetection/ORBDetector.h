#pragma once

#include "Core/Image/ImageContainer.h"
#include "Core/DTO/FeatureContainer.h"

#include <opencv2/features2d.hpp>
#include <QList>

class ORBDetector
{
private:
    int numFeatures = 10000;

public:
    ORBDetector();
    ~ORBDetector();
    QList<FeatureContainer> StartDetection(QList<ImageContainer> &imageContainerList);


    int getNumFeatures() const;
    void setNumFeatures(int value);
};
