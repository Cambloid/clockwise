#pragma once

#include "Core/Image/ImageContainer.h"
#include "Core/DTO/FeatureContainer.h"

#include <QList>

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

class ShiTomasiDetector
{
private:
    int numFeatures = 1000;

public:
    ShiTomasiDetector();
    ~ShiTomasiDetector();
    QList<FeatureContainer> StartDetection(QList<ImageContainer> &imageContainerList);


    int getNumFeatures() const;
    void setNumFeatures(int value);
};
