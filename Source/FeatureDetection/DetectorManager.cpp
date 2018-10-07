#include "DetectorManager.h"

DetectorManager::DetectorManager(SettingsData &settingsData)
{
    this->settingsData = settingsData;
}

ImageContainer DetectorManager::StartDetection(ImageContainer &imageContainer)
{
    this->imageContainer = imageContainer;

    if(this->settingsData.getDetectorType() == DetectorType::CornerHarris) {
        this->configureCornerHarris();
        this->imageContainer = this->cornerHarris.StartDetection(this->imageContainer);

    } else if (this->settingsData.getDetectorType() == DetectorType::ShiTomasi) {
        this->configureShiTomasi();
        this->imageContainer = this->shiTomasi.StartDetection(this->imageContainer);

    } else if (this->settingsData.getDetectorType() == DetectorType::SIFT) {
        this->configureSIFT();
        this->imageContainer = this->sift.StartDetecion(this->imageContainer);
    }

    return this->imageContainer;
}


void DetectorManager::configureCornerHarris()
{
    this->cornerHarris.setThreshold(this->settingsData.getThreshold());
}

void DetectorManager::configureShiTomasi()
{
    this->shiTomasi.setNumFeatures(this->settingsData.getNumFeatures());
}


void DetectorManager::configureSIFT()
{

}
