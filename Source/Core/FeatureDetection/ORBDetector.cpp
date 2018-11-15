#include "ORBDetector.h"


ORBDetector::ORBDetector() {}

ORBDetector::~ORBDetector() {}

std::vector<FeatureContainer> ORBDetector::StartDetection(std::vector<ImageContainer> &imageContainerList)
{

    std::vector<cv::Mat> newImage;
    std::vector<FeatureContainer> featureContainerList;
    int numImages = imageContainerList.size();
    int imgIdx = 1;


    foreach(ImageContainer image, imageContainerList) {
        cv::Mat tmpImage = image.getImage().clone();
         qDebug() << "Working on Image " << imgIdx << " / " << numImages;

        cv::Ptr<cv::ORB> orbInstance = cv::ORB::create(this->getNumFeatures());

        std::vector<cv::KeyPoint> keyPointCollection;
        orbInstance->detect(tmpImage, keyPointCollection);

        cv::Mat descriptor;
        orbInstance->compute(tmpImage, keyPointCollection, descriptor);

        for( int i = 0; i < keyPointCollection.size(); i++) {
            circle(tmpImage, keyPointCollection[i].pt, 3, cv::Scalar(255, 255, 255), 2, 8, 0);
        }

        newImage.push_back(tmpImage);
        featureContainerList.push_back(FeatureContainer(keyPointCollection));
        imgIdx++;
    }

    qDebug() << "Work finished";

    return featureContainerList;
}


int ORBDetector::getNumFeatures() const
{
    return numFeatures;
}

void ORBDetector::setNumFeatures(int value)
{
    numFeatures = value;
}
