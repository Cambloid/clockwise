#include "SIFTDetector.h"

SIFTDetector::SIFTDetector() {}

SIFTDetector::~SIFTDetector() {}

QList<FeatureContainer> SIFTDetector::StartDetection(QList<ImageContainer> &imageContainerList)
{

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

        cv::Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create(8000);

        std::vector<cv::KeyPoint> keypointCollection;
        sift->detect(imageGrey, keypointCollection);

        newImage.append(tmpImage);
        featureContainerList.append(FeatureContainer(keypointCollection));
        imgIdx++;
    }
    std::cout <<  "Work finished" << std::endl ;

    return featureContainerList;
}
