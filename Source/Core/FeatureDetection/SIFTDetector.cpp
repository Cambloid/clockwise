#include "SIFTDetector.h"

SIFTDetector::SIFTDetector() {}

SIFTDetector::~SIFTDetector() {}

std::vector<FeatureContainer> SIFTDetector::StartDetection(std::vector<ImageContainer> &imageContainerList)
{

    std::vector<cv::Mat> newImage;
    std::vector<FeatureContainer> featureContainerList;
    uint32_t numImages = static_cast<uint32_t>(imageContainerList.size());
    int imgIdx = 1;

    foreach(ImageContainer image, imageContainerList) {
        cv::Mat tmpImage = image.getImage().clone();
        std::cout << "Working on Image " << imgIdx << " / " << numImages << std::endl;

        // Convert image to a grey image
        cv::Mat imageGrey;
        cv::cvtColor(tmpImage, imageGrey, cv::COLOR_BGR2GRAY);

        cv::Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create(100);

        std::vector<cv::KeyPoint> keypointCollection;
        sift->detect(imageGrey, keypointCollection);

        newImage.push_back(tmpImage);
        featureContainerList.push_back(FeatureContainer(keypointCollection));
        imgIdx++;
    }
    std::cout <<  "Work finished" << std::endl ;

    return featureContainerList;
}
