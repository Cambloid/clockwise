#include "DetectorManager.h"

DetectorManager::DetectorManager(SettingsBase &settingsBase)
{
    this->settingsBase = settingsBase;
}

QList<FeatureContainer> DetectorManager::StartDetection(QList<ImageContainer> &imagecontainerList)
{
    this->imageContainerList = imagecontainerList;

    if(this->settingsBase.detectorType == DetectorType::CornerHarris) {
        this->configureCornerHarris();
        this->featureContainerList = this->cornerHarris.StartDetection(this->imageContainerList);

    } else if (this->settingsBase.detectorType == DetectorType::ShiTomasi) {
        this->configureShiTomasi();
        this->featureContainerList = this->shiTomasi.StartDetection(this->imageContainerList);

    } else if (this->settingsBase.detectorType == DetectorType::SIFT) {
        this->featureContainerList = this->sift.StartDetection(this->imageContainerList);

    } else if (this->settingsBase.detectorType == DetectorType::ORB) {
        this->configureORB();
        this->featureContainerList = this->orb.StartDetection(this->imageContainerList);

    }
    return this->featureContainerList;
}

void DetectorManager::configureCornerHarris()
{
    this->cornerHarris.setThreshold(this->settingsBase.cornerHarris.threshold);
}

void DetectorManager::configureShiTomasi()
{
    this->shiTomasi.setNumFeatures(this->settingsBase.shiTomasi.numFeatures);
}

void DetectorManager::configureORB()
{
    this->orb.setNumFeatures(this->settingsBase.orb.numFeatures);
}
