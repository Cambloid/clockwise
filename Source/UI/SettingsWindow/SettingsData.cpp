#include "UI/SettingsWindow/SettingsData.h"


/*!

*/
DetectorType SettingsData::getDetectorType() const
{
    return this->detectorType;
}

/*!

*/
void SettingsData::setDetectorType(DetectorType value)
{
    this->detectorType = detectorType;
}

/*!

*/
int SettingsData::getThreshold() const
{
    return this->threshold;
}

/*!

*/
void SettingsData::setThreshold(int value)
{
    this->threshold = value;
}

/*!

*/
int SettingsData::getNumFeatures() const
{
    return this->numFeatures;
}

/*!

*/
void SettingsData::setNumFeatures(int value)
{
    this->numFeatures = value;
}
