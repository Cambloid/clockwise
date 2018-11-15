#pragma once

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
        this->detectorType = DetectorType::ORB;
    }

    struct ShiTomasi {
        int numFeatures;
        ShiTomasi() {
            this->numFeatures = 1;
        }
    } shiTomasi;

    struct CornerHarris {
        int threshold;

        CornerHarris() {
            threshold = 200;
        }
    } cornerHarris;

    struct ORB {
        int numFeatures;
        ORB()  {
           numFeatures = 10;
        }

    } orb;

    struct SIFT {

        SIFT()  {

        }

    } sift;
};
