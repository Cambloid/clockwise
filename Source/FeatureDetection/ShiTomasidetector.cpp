#include "FeatureDetection/ShiTomasiDetector.h"

ShiTomasiDetector::ShiTomasiDetector() {}

ShiTomasiDetector::~ShiTomasiDetector() {}

QList<FeatureContainer> ShiTomasiDetector::StartDetection(QList<ImageContainer> &imageContainerList) {

    QList<cv::Mat> newImage;
    QList<FeatureContainer> featureContainerList;

    int numImages = imageContainerList.count();
    int imgIdx = 1;

    foreach(ImageContainer image, imageContainerList) {
        cv::Mat tmpImage = image.getImage().clone();
        std::cout << "Working on Image " << imgIdx << " / " << numImages << std::endl;

        // Convert image to a grey image
        cv::Mat imageGrey;
        cv::cvtColor(tmpImage, imageGrey, cv::COLOR_BGR2GRAY);


        // Detecting corners
        std::vector<cv::Point2f> corners;
        cv::goodFeaturesToTrack(imageGrey, corners, this->numFeatures, 0.01, 10);

        /*
            Goal: Extract X Y Coordinate from mat
        */
        // Drawing a circle around corners
        for( int i = 0; i < corners.size(); i++ ) {
            circle(tmpImage, corners[i], 3, cv::Scalar(255, 255, 255), 2, 8, 0);
        }

        newImage.append(tmpImage);
        //featureContainerList.append(corners)
        imgIdx++;
    }

    std::cout <<  "Work finished" << std::endl ;

    return featureContainerList;
};


int ShiTomasiDetector::getNumFeatures() const
{
    return numFeatures;
}

void ShiTomasiDetector::setNumFeatures(int value)
{
    numFeatures = value;
}
