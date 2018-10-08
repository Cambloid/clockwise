#ifndef SETTINGSDATABASE_H
#define SETTINGSDATABASE_H

/*!

*/
enum DetectorType {
    CornerHarris,
    ShiTomasi,
    SIFT,
    ORB,
};

/*!

*/
struct SettingsBase {

    DetectorType detectorType;

    SettingsBase() {
        this->detectorType = DetectorType::CornerHarris;
    }

    struct ShiTomasi {
        int numFeatures;
        ShiTomasi() {
            this->numFeatures = 10000;
        }
    } shiTomasi;

    struct CornerHarris {
        int threshold;

        CornerHarris() {
            threshold = 200;
        }
    } cornerHarris;
};


#endif // SETTINGSDATABASE_H

