#include "FeatureDetection/CornerHarrisDetector.h"


CornerHarrisDetector::CornerHarrisDetector() {}


CornerHarrisDetector::~CornerHarrisDetector() {}

int CornerHarrisDetector::getThreshold() {
    return this->threshold;
}

void CornerHarrisDetector::setThreshold(int threshold) {
    this->threshold = threshold;
}




ImageContainer CornerHarrisDetector::StartDetection(ImageContainer &imageContainer) {

    QList<cv::Mat> newImage;

    int numImages = imageContainer.getOCV_MatList().count();
    int imgIdx = 1;

    // Detector parameters
    int blockSize = 2;
    int apertureSize = 3;
    double k = 0.04;

    foreach(cv::Mat image, imageContainer.getOCV_MatList()) {
        cv::Mat tmpImage = image.clone();
        std::cout << "Working on Image " << imgIdx << " / " << numImages << std::endl;

        // Convert image to a grey image
        cv::Mat imageGrey;
        cv::cvtColor(tmpImage, imageGrey, cv::COLOR_BGR2GRAY);

        // Create threshold image matrix
        cv::Mat dst, dst_norm, dst_norm_scaled;
        dst = cv::Mat::zeros(imageGrey.size(), CV_32FC1);

        // Detecting corners
        cv::cornerHarris(imageGrey, dst, blockSize, apertureSize, k, cv::BORDER_DEFAULT);

        // Normalizing
        cv::normalize(dst, dst_norm, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
        cv::convertScaleAbs(dst_norm, dst_norm_scaled);

        // Drawing a circle around corners
        for(int j = 0; j < dst_norm.rows; j++)
        {
            for(int i = 0; i < dst_norm.cols; i++)
            {
                if((int)dst_norm.at<float>(j,i) > this->threshold)
                {
                    // Draw circle in image
                    cv::circle(tmpImage, cv::Point(i, j), 5, cv::Scalar(255, 255, 255), 2, 8, 0);
                }
            }
        }

        if(dst_norm_scaled.empty()) // Check for invalid input
        {
            std::cout <<  "Could not open or find the image" << std::endl ;
        }

        newImage.append(tmpImage);
        imgIdx++;
    }

    std::cout <<  "Work finished" << std::endl ;

    return ImageContainer(&newImage);
}
