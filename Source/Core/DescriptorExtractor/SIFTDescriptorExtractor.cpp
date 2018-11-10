#include "SIFTDescriptorExtractor.h"

SIFTDescriptorExtractor::SIFTDescriptorExtractor() {}

QList<SIFTDescriptorContainer> SIFTDescriptorExtractor::StartExtraction(QList<ImageContainer> &imgContainerList, QList<FeatureContainer> &featureContainerList)
{
    QList<SIFTDescriptorContainer> descriptorList;
    cv::Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create();

    ImageContainer imgContainer;
    FeatureContainer featureContainer;

    for(int i = 0; i < imgContainerList.count(); i++) {

        std::cout << "Extract Descriptor of Image: " << i + 1 << " of " << imgContainerList.count() << std::endl;

        imgContainer = imgContainerList.at(i);
        featureContainer = featureContainerList.at(i);

        cv::Mat descriptor;
        //sift->compute(imgContainer.getImage(), featureContainer.keyPointList, descriptor);

        descriptorList.append(SIFTDescriptorContainer(descriptor));
    }

    return descriptorList;
}

