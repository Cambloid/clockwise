#ifndef DETECTORMANAGER_H
#define DETECTORMANAGER_H

#include "DTO/SettingsBase.h"

#include "Image/ImageContainer.h"
#include "FeatureDetection/CornerHarrisDetector.h"
#include "FeatureDetection/ShiTomasidetector.h"
#include "FeatureDetection/ORBDetector.h"
#include "FeatureDetection/SIFTDetector.h"

class DetectorManager
{
private:
    ImageContainer imageContainer;

    SettingsBase settingsBase;
    CornerHarrisDetector cornerHarris;
    ShiTomasiDetector shiTomasi;
    ORBDetector orb;
    SIFTDetector sift;

public:
    DetectorManager(SettingsBase &settingsData);
    ImageContainer StartDetection(ImageContainer &imagecontainer);

private:
    void configureCornerHarris();
    void configureShiTomasi();
    void configureORB();

};

#endif // DETECTORMANAGER_H
