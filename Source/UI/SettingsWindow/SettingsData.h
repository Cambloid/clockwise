#ifndef SETTINGSDATA_H
#define SETTINGSDATA_H

/*!

*/
enum DetectorType {
    CornerHarris,
    ShiTomasi,
    SIFT
};

/*!

*/
class SettingsData {
private:
    DetectorType detectorType = DetectorType::CornerHarris;

    // CornerHarris settings
    int threshold = 200;

    // ShiTomasi settings
    int numFeatures = 10000;


public:
    DetectorType getDetectorType() const;
    void setDetectorType(DetectorType detectorType);

    int getThreshold() const;
    void setThreshold(int value);

    int getNumFeatures() const;
    void setNumFeatures(int value);
};


#endif // SETTINGSDATA_H

