#include "KLTFeatureTracker.h"

KLTFeatureTracker::KLTFeatureTracker(QList<ImageContainer> &imageList, QList<FeatureContainer> &featureContainerList)
{
    this->imageList = imageList;
    this->featureContainerList = featureContainerList;
}



void KLTFeatureTracker::StartTracking()
{

    //this function automatically gets rid of points for which tracking fails

    if(this->imageList.count() != this->featureContainerList.count()) {
        std::cout << "List count are not equal" << std::endl;
        return;
    }

    ImageContainer image;
    FeatureContainer featureContainer;
    ImageContainer prevImage;
    FeatureContainer prevFeatureContainer;

    std::vector<SingleTrackResult> resultList;

    for(int i = 0; i < this->imageList.count(); i++) {
        if(i == 0) {
            prevImage = this->imageList.at(i);
            prevFeatureContainer = this->featureContainerList.at(i);
        }

        image = this->imageList.at(i);
        featureContainer = this->featureContainerList.at(i);

        resultList.push_back(this->TrackImagePair(prevImage, prevFeatureContainer, image, featureContainer));
    }



    // Print results (tmp)
    for(int i = 0; i < resultList.size(); i++) {
        for(int err = 0; err < resultList.at(i).err.size(); err++) {
            std::cout << "Resultlist idx:" << i << std::endl;
            std::cout << "Resultlist err/status index:" << err << std::endl;
            std::cout << "Error:" << resultList.at(i).err.at(err) << std::endl;
            std::cout << "Status:" << resultList.at(i).status.at(err) << std::endl;
            std::cout << "-----------------------------------" << std::endl;
        }
    }




}


SingleTrackResult KLTFeatureTracker::TrackImagePair(ImageContainer prevImage, FeatureContainer prevImageFeatureContainer, ImageContainer image, FeatureContainer imageFeatureContainer)
{

    std::vector<uchar> status;
    std::vector<float> err;

    cv::Size winSize= cv::Size(21, 21);
    cv::TermCriteria termcrit= cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.01);

    cv::calcOpticalFlowPyrLK(prevImage.getImage(), image.getImage(), prevImageFeatureContainer.keyPointListPoint2f, imageFeatureContainer.keyPointListPoint2f, status, err, winSize, 3, termcrit, 0, 0.001);

    return SingleTrackResult { status, err };
}
