#ifndef DETECTORMANAGER_H
#define DETECTORMANAGER_H

#include "UI/SettingsWindow/SettingsData.h"
#include "Image/ImageContainer.h"
#include "FeatureDetection/CornerHarrisDetector.h"
#include "FeatureDetection/ShiTomasidetector.h"
#include "FeatureDetection/SIFTDetector.h"

class DetectorManager
{
private:
    SettingsData settingsData;
    ImageContainer imageContainer;

    CornerHarrisDetector cornerHarris;
    ShiTomasiDetector shiTomasi;
    SIFTDetector sift;

public:
    DetectorManager(SettingsData &settingsData);
    ImageContainer StartDetection(ImageContainer &imagecontainer);

private:
    void configureCornerHarris();
    void configureShiTomasi();
    void configureSIFT();



};

#endif // DETECTORMANAGER_H
