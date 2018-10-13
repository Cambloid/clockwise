#pragma once

#include <QList>

#include "DTO/SettingsBase.h"
#include "DTO/FeatureContainer.h"

#include "Image/ImageContainer.h"
#include "FeatureDetection/CornerHarrisDetector.h"
#include "FeatureDetection/ShiTomasidetector.h"
#include "FeatureDetection/ORBDetector.h"
#include "FeatureDetection/SIFTDetector.h"

class DetectorManager
{
private:
    QList<ImageContainer> imageContainerList;
    QList<FeatureContainer> featureContainerList;

    SettingsBase settingsBase;
    CornerHarrisDetector cornerHarris;
    ShiTomasiDetector shiTomasi;
    ORBDetector orb;
    SIFTDetector sift;

public:
    DetectorManager(SettingsBase &settingsData);
    QList<FeatureContainer> StartDetection(QList<ImageContainer> &imagecontainerList);

private:
    void configureCornerHarris();
    void configureShiTomasi();
    void configureORB();
};
