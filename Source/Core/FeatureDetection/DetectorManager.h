#pragma once

#include <QList>

#include "Core/DTO/SettingsBase.h"
#include "Core/DTO/FeatureContainer.h"

#include "Core/Image/ImageContainer.h"
#include "Core/FeatureDetection/CornerHarrisDetector.h"
#include "Core/FeatureDetection/ShiTomasidetector.h"
#include "Core/FeatureDetection/ORBDetector.h"
#include "Core/FeatureDetection/SIFTDetector.h"

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
