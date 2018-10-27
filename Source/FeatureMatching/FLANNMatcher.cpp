#include "FLANNMatcher.h"

FLANNMatcher::FLANNMatcher(QList<ImageContainer> &imageList, QList<SIFTDescriptorContainer> &siftDescriptorContainer)
{
    this->imageList = imageList;
    this->siftDescriptorContainer = siftDescriptorContainer;
}

std::vector<cv::DMatch> FLANNMatcher::matchFeatures(cv::FlannBasedMatcher matcher, cv::Mat descriptor1, cv::Mat descriptor2) {
    std::vector<cv::DMatch> matchList;
    matcher.match(descriptor1, descriptor2, matchList);
    return matchList;
}

std::vector<DMatchContainer> FLANNMatcher::StartMatching()
{

    if(this->imageList.count() != this->siftDescriptorContainer.count()) {
        return std::vector<DMatchContainer>();
    }

    ImageContainer currImage;
    ImageContainer prevImage;
    SIFTDescriptorContainer descContainer;
    SIFTDescriptorContainer prevDescContainer;

    std::vector<cv::DMatch> matchList;
    cv::FlannBasedMatcher matcher;

    std::vector<DMatchContainer> dmatchContainerList;


    // Foreach image
    for(int i = 0; i < imageList.count(); i++) {
        currImage = this->imageList.at(i);
        descContainer = this->siftDescriptorContainer.at(i);

        if(i == 0) {
            prevImage = this->imageList.at(i);
            prevDescContainer = this->siftDescriptorContainer.at(i);
            continue;
        }

        matchList = this->matchFeatures(matcher, prevDescContainer.descriptor, descContainer.descriptor);


        // Get Max / Min Distance
        double max_dist = 0;
        double min_dist = 100;
        for(int i = 0; i < prevDescContainer.descriptor.rows; i++)
        {
            double dist = matchList[i].distance;
            if(dist < min_dist) min_dist = dist;
            if(dist > max_dist) max_dist = dist;
        }

        // Filter good matches
        std::vector<cv::DMatch> good_matches;
        for( int i = 0; i < prevDescContainer.descriptor.rows; i++ )
        {
            if( matchList[i].distance <= cv::max(2 * min_dist, 0.02))
            {
                good_matches.push_back(matchList[i]);
            }
        }

        // Add good matches to container collection
        dmatchContainerList.push_back(DMatchContainer(good_matches));

        prevImage = this->imageList.at(i);
        descContainer = this->siftDescriptorContainer.at(i);
    }

    return dmatchContainerList;
}
