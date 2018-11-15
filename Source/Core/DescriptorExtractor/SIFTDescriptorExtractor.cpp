#include "SIFTDescriptorExtractor.h"

SIFTDescriptorExtractor::SIFTDescriptorExtractor() {}

std::vector<SIFTDescriptorContainer> SIFTDescriptorExtractor::StartExtraction(std::vector<ImageContainer> &imgContainerList, std::vector<FeatureContainer> &featureContainerList)
{
    std::vector<SIFTDescriptorContainer> descriptorList;
    cv::Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create();

    ImageContainer imgContainer;
    FeatureContainer featureContainer;

    for(int i = 0; i < imgContainerList.size(); i++) {

        std::cout << "Extract Descriptor of Image: " << i + 1 << " of " << imgContainerList.size() << std::endl;

        imgContainer = imgContainerList.at(i);
        featureContainer = featureContainerList.at(i);

        cv::Mat descriptor;
        //sift->compute(imgContainer.getImage(), featureContainer.keyPointList, descriptor);

        descriptorList.push_back(SIFTDescriptorContainer(descriptor));
    }

    return descriptorList;
}

