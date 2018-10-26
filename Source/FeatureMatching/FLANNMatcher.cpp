#include "FLANNMatcher.h"

FLANNMatcher::FLANNMatcher(QList<ImageContainer> &imageList, QList<FeatureContainer> &featureContainerList)
{
    this->imageList = imageList;
    this->featureContainerList = featureContainerList;
}

cv::Mat computeDescriptor(cv::Ptr<cv::xfeatures2d::SIFT> &sift, ImageContainer &imgContainer, FeatureContainer &featureContainer)
{
    cv::Mat descriptor;
    sift->compute(imgContainer.getImage(), featureContainer.keyPointList, descriptor);

    return descriptor;
}

std::vector<cv::DMatch> matchFeatures(cv::FlannBasedMatcher matcher, cv::Mat descriptor1, cv::Mat descriptor2) {
    std::vector<cv::DMatch> matchList;
    matcher.match(descriptor1, descriptor2, matchList);
    return matchList;
}

void FLANNMatcher::StartMatching()
{

    if(imageList.count() != featureContainerList.count()) {
        return;
    }

    cv::Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create();

    ImageContainer prevImgContainer;
    FeatureContainer prevFeatureContainer;
    ImageContainer imgContainer;
    FeatureContainer featureContainer;

    cv::Mat descriptor;
    cv::Mat prevDescriptor;

    std::vector<cv::DMatch> matchList;

    cv::FlannBasedMatcher matcher;

    for(int i = 0; i < imageList.count(); i++) {

        if(i == 0)
        {
            prevImgContainer = imageList.at(i);
            prevFeatureContainer = featureContainerList.at(i);
            continue;
        }


        imgContainer = imageList.at(i);
        featureContainer = featureContainerList.at(i);

        descriptor = computeDescriptor(sift, imgContainer, featureContainer);
        matchList = matchFeatures(matcher, prevDescriptor, descriptor);

        double max_dist = 0;
        double min_dist = 100;
        for(int i = 0; i < descriptor.rows; i++)
        {
            double dist = matchList[i].distance;
            if( dist < min_dist ) min_dist = dist;
            if( dist > max_dist ) max_dist = dist;
        }

        std::vector<cv::DMatch> good_matches;
        for( int i = 0; i < descriptor.rows; i++ )
        {
            if( matchList[i].distance <= cv::max(2 * min_dist, 0.02))
            {
                good_matches.push_back( matchList[i]);
            }
        }


        //std::cout << "Num Matches: "



        // cv::xfeatures2d::SIFT::create()

    }
}
