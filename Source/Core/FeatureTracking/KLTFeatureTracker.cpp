#include "KLTFeatureTracker.h"

KLTFeatureTracker::KLTFeatureTracker(QList<ImageContainer> &imageList, QList<FeatureContainer> &featureContainerList)
{
    this->imageList = imageList;
    this->featureContainerList = featureContainerList;
}

void KLTFeatureTracker::StartTracking()
{

    /*

https://docs.opencv.org/3.4/d7/d8b/tutorial_py_lucas_kanade.html
https://www.learnopencv.com/object-tracking-using-opencv-cpp-python/
https://docs.opencv.org/3.1.0/d5/dab/tutorial_sfm_trajectory_estimation.html
https://docs.opencv.org/3.4/dc/d6b/group__video__track.html#ga473e4b886d0bcc6b65831eb88ed93323

    */

    //this function automatically gets rid of points for which tracking fails

    if(this->imageList.count() != this->featureContainerList.count()) {
        std::cout << "List count are not equal" << std::endl;
        return;
    }


    //FeatureContainer featureContainerFromFirstImage = this->featureContainerList.first();


    ImageContainer currImage;
    FeatureContainer currFeatureContainer;
    ImageContainer prevImage;
    FeatureContainer prevFeatureContainer;

    std::vector<SingleTrackResult> resultList;
    // Start with first image features and track them through all images
    for(int i = 0; i < this->imageList.count(); i++) {
        if(i == 0) {
            prevImage = this->imageList.at(i);
            prevFeatureContainer = this->featureContainerList.at(i);
            continue;
        }

        currImage = this->imageList.at(i);
        currFeatureContainer = this->featureContainerList.at(i);


        //cv::Tracker trackerInst = cv::Tracker
        resultList.push_back(
                    this->TrackImagePair(prevImage, prevFeatureContainer, currImage, currFeatureContainer)
                    );

        prevImage = currImage;
        prevFeatureContainer = currFeatureContainer;

    }


    // Print results (tmp)
    for(int i = 0; i < resultList.size(); i++) {
        for(int err = 0; err < resultList.at(i).err.size(); err++) {
            std::cout << "Resultlist idx:" << i << std::endl;
            std::cout << "Resultlist err/status index:" << err << std::endl;
            std::cout << "Error:"  << resultList.at(i).err.at(err) << std::endl;
            std::cout << "Status:" << resultList.at(i).status.at(err) << std::endl;
            std::cout << "-----------------------------------" << std::endl;
        }
    }



}

SingleTrackResult KLTFeatureTracker::TrackImagePair(ImageContainer &prevImage, FeatureContainer &prevImageFeatureContainer, ImageContainer &image, FeatureContainer &imageFeatureContainer)
{

    std::vector<uchar> status;
    std::vector<float> err;

    cv::Size winSize= cv::Size(21, 21);
    cv::TermCriteria termcrit= cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.01);

    cv::calcOpticalFlowPyrLK(prevImage.getImage(), image.getImage(), prevImageFeatureContainer.keyPointListPoint2f, imageFeatureContainer.keyPointListPoint2f, status, err, winSize, 3, termcrit, 0, 0.001);





    // Filter Points
    int indexCorrection = 0;
    for( int i = 0; i < status.size(); i++)
    {
        cv::Point2f pt = prevImageFeatureContainer.keyPointListPoint2f.at(i- indexCorrection);
        if ((status.at(i) == 0) || (pt.x < 0) || (pt.y < 0))	{
            if((pt.x < 0) || (pt.y < 0)) {
                status.at(i) = 0;
            }
            //prevImageFeatureContainer.keyPointListPoint2f.erase(prevImageFeatureContainer.keyPointListPoint2f.begin() + i - indexCorrection);
            imageFeatureContainer.keyPointListPoint2f.erase(imageFeatureContainer.keyPointListPoint2f.begin() + i - indexCorrection);
            indexCorrection++;
        }
    }


    return SingleTrackResult { status, err };
}
