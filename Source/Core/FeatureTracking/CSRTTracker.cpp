#include "CSRTTracker.h"

CSRTTracker::CSRTTracker(std::vector<ImageContainer> &imageList, std::vector<FeatureContainer> &featureContainerList)
{
    this->imageList = imageList;
    this->featureContainerList = featureContainerList;
}

void CSRTTracker::StartTracking()
{


    /*
    - Take Features from first Image
    - Track them through all Images
    - Return Object with Features and (x,y animation)
*/


    /*

        https://www.learnopencv.com/object-tracking-using-opencv-cpp-python/
        https://docs.opencv.org/3.1.0/d5/dab/tutorial_sfm_trajectory_estimation.html
        https://docs.opencv.org/3.4/dc/d6b/group__video__track.html#ga473e4b886d0bcc6b65831eb88ed93323
        http://www.votchallenge.net/
        https://www.youtube.com/watch?v=jZoUalMMZ_0
        https://docs.opencv.org/3.4/d5/dab/tutorial_sfm_trajectory_estimation.html
        https://docs.opencv.org/3.4/d7/d8b/tutorial_py_lucas_kanade.html
        https://www.docs.opencv.org/3.4.1/d3/de9/structcv_1_1TrackerCSRT_1_1Params.html
    */

    //this function automatically gets rid of points for which tracking fails

    if(this->imageList.size() <= 0) {
        qInfo() << "Imagelist ist empty";
        return;
    }

    //FeatureContainer featureContainerFromFirstImage = this->featureContainerList.first();

    FeatureContainer featuresFirstImage = this->featureContainerList.at(0);
    ImageContainer firstImage = this->imageList.at(0);
    cv::Ptr<cv::TrackerCSRT> csrtTracker = cv::TrackerCSRT::create();
    cv::Rect2d featureRect;
    bool isOk = true;

    // Track each Feature from first image though all images
    for(int t = 0; t < featuresFirstImage.keyPointList.size(); t++) {

        featureRect = cv::Rect2d(featuresFirstImage.keyPointList.at(t).pt.x - 50,
                                 featuresFirstImage.keyPointList.at(t).pt.y - 50,
                                 100,
                                 100);

        csrtTracker->init(firstImage.getImage(), featureRect);

        // TODO: Check somehow that the tracker is of
        isOk = true;
        for(int i = 0; i < this->imageList.size(); i++) {
            isOk = csrtTracker->update(firstImage.getImage(), featureRect);
            if(!isOk) {
                break; // Track next feature
            }

         qDebug() << "Feature [" << t << "] -> " << "(" << featureRect.x << "/" << featureRect.y << ")";

         //cv::Mat test = this->imageList.at(i).getImage();
         //cv::rectangle(, featureRect, cv::Scalar( 255, 0, 0 ), 2, 1 );

        }

    }



}
