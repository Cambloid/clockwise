#include "FeatureDetection/ShiTomasiDetector.h"

ShiTomasiDetector::ShiTomasiDetector() {}

ShiTomasiDetector::~ShiTomasiDetector() {}

ImageContainer ShiTomasiDetector::StartDetection(ImageContainer &imageContainer) {

    QList<cv::Mat> newImage;
    int numImages = imageContainer.getOCV_MatList().count();
    int imgIdx = 1;

    foreach(cv::Mat image, imageContainer.getOCV_MatList()) {
        cv::Mat tmpImage = image.clone();
        std::cout << "Working on Image " << imgIdx << " / " << numImages << std::endl;

        // Convert image to a grey image
        cv::Mat imageGrey;
        cv::cvtColor(tmpImage, imageGrey, CV_BGR2GRAY);


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
        imgIdx++;
    }

    std::cout <<  "Work finished" << std::endl ;

    return ImageContainer(&newImage);
};


int ShiTomasiDetector::getNumFeatures() const
{
    return numFeatures;
}

void ShiTomasiDetector::setNumFeatures(int value)
{
    numFeatures = value;
}
