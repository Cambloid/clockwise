#include "ORBDetector.h"

ORBDetector::ORBDetector() {}

ORBDetector::~ORBDetector() {}

ImageContainer ORBDetector::StartDetecion(ImageContainer &imageContainer)
{

    QList<cv::Mat> newImage;
    int numImages = imageContainer.getOCV_MatList().count();
    int imgIdx = 1;
    foreach(cv::Mat image, imageContainer.getOCV_MatList()) {
        cv::Mat tmpImage = image.clone();
        std::cout << "Working on Image " << imgIdx << " / " << numImages << std::endl;

        cv::Ptr<cv::ORB> orbInstance = cv::ORB::create();

        std::vector<cv::KeyPoint> keyPointCollection;
        orbInstance->detect(tmpImage, keyPointCollection);

        cv::Mat descriptor;
        orbInstance->compute(tmpImage, keyPointCollection, descriptor);

        for( int i = 0; i < keyPointCollection.size(); i++) {
            circle(tmpImage, keyPointCollection[i].pt, 3, cv::Scalar(255, 255, 255), 2, 8, 0);
        }

        newImage.append(tmpImage);
        imgIdx++;
    }

    std::cout <<  "Work finished" << std::endl;

    return ImageContainer(&newImage);
}
