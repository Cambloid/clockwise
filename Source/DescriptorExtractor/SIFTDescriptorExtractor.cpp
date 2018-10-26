#include "DescriptorExtractor/SIFTDescriptorExtractor.h"


SIFTDescriptorExtractor::SIFTDescriptorExtractor() {}


QList<cv::Mat> SIFTDescriptorExtractor::StartExtraction(QList<ImageContainer> &imgContainerList, QList<FeatureContainer> &featureContainerList)
{
    QList<cv::Mat> descriptorList;
    cv::Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create();

    ImageContainer imgContainer;
    FeatureContainer featureContainer;

    for(int i = 0; i < imgContainerList.count(); i++) {
        imgContainer = imgContainerList.at(i);
        featureContainer = featureContainerList.at(i);

        cv::Mat descriptor;
        sift->compute(imgContainer.getImage(), featureContainer.keyPointList, descriptor);

        descriptorList.append(descriptor);
    }

    return descriptorList;
}

