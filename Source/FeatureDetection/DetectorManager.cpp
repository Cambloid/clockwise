#include "DetectorManager.h"

DetectorManager::DetectorManager(SettingsBase &settingsBase)
{
    this->settingsBase = settingsBase;
}

ImageContainer DetectorManager::StartDetection(ImageContainer &imageContainer)
{
    this->imageContainer = imageContainer;



    if(this->settingsBase.detectorType == DetectorType::CornerHarris) {
        this->configureCornerHarris();
        this->imageContainer = this->cornerHarris.StartDetection(this->imageContainer);



    } else if (this->settingsBase.detectorType == DetectorType::ShiTomasi) {
        this->configureShiTomasi();
        this->imageContainer = this->shiTomasi.StartDetection(this->imageContainer);



    } else if (this->settingsBase.detectorType == DetectorType::SIFT) {



    } else if (this->settingsBase.detectorType == DetectorType::ORB) {
        this->configureORB();
        this->imageContainer = this->orb.StartDetecion(this->imageContainer);

    }

    return this->imageContainer;
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
    //SettingsORB *settingsORB = dynamic_cast<SettingsORB*>(&this->settingsBase);
    //this->orb.setNumFeatures(settingsORB->getNumFeatures());
}
