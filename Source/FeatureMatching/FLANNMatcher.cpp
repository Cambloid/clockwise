#include "FLANNMatcher.h"

FLANNMatcher::FLANNMatcher(QList<ImageContainer> &imageList, QList<FeatureContainer> &featureContainerList)
{
    this->imageList = imageList;
    this->featureContainerList = featureContainerList;
}

void FLANNMatcher::StartMatching()
{
    if(imageList.count() != featureContainerList.count()) {
        return;
    }

    for(int i = 0; i < imageList.count(); i++) {
        ImageContainer imgContainer       = imageList.at(i);
        FeatureContainer featureContainer = featureContainerList.at(i);

       // cv::xfeatures2d::SIFT::create()

    }
}
