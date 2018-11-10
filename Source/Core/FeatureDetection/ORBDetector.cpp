#include "ORBDetector.h"


ORBDetector::ORBDetector() {}

ORBDetector::~ORBDetector() {}

QList<FeatureContainer> ORBDetector::StartDetection(QList<ImageContainer> &imageContainerList)
{

    QList<cv::Mat> newImage;
    QList<FeatureContainer> featureContainerList;
    int numImages = imageContainerList.count();
    int imgIdx = 1;


    foreach(ImageContainer image, imageContainerList) {
        cv::Mat tmpImage = image.getImage().clone();
        std::cout << "Working on Image " << imgIdx << " / " << numImages << std::endl;

        cv::Ptr<cv::ORB> orbInstance = cv::ORB::create(this->getNumFeatures());

        std::vector<cv::KeyPoint> keyPointCollection;
        orbInstance->detect(tmpImage, keyPointCollection);

        cv::Mat descriptor;
        orbInstance->compute(tmpImage, keyPointCollection, descriptor);

        for( int i = 0; i < keyPointCollection.size(); i++) {
            circle(tmpImage, keyPointCollection[i].pt, 3, cv::Scalar(255, 255, 255), 2, 8, 0);
        }

        newImage.append(tmpImage);
        featureContainerList.append(FeatureContainer(keyPointCollection));
        imgIdx++;
    }

    std::cout <<  "Work finished" << std::endl;

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
