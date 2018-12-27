#pragma once

#include <QList>

#include "Source/Core/DTO/SettingsBase.h"
#include "Source/Core/DTO/FeatureContainer.h"

#include "Source/Core/Image/ImageContainer.h"
#include "Source/Core/FeatureDetection/CornerHarrisDetector.h"
#include "Source/Core/FeatureDetection/ShiTomasidetector.h"
#include "Source/Core/FeatureDetection/ORBDetector.h"
#include "Source/Core/FeatureDetection/SIFTDetector.h"

class DetectorManager
{
private:
    std::vector<ImageContainer> imageContainerList;
    std::vector<FeatureContainer> featureContainerList;

    SettingsBase settingsBase;
    CornerHarrisDetector cornerHarris;
    ShiTomasiDetector shiTomasi;
    ORBDetector orb;
    SIFTDetector sift;

public:
    DetectorManager(SettingsBase &settingsData);
    std::vector<FeatureContainer> StartDetection(std::vector<ImageContainer> &imagecontainerList);

private:
    void configureCornerHarris();
    void configureShiTomasi();
    void configureORB();
};
