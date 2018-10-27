#pragma once

#include <QList>
#include <opencv2/core.hpp>

struct DMatchContainer 
{
    std::vector<cv::DMatch> dMatchList;

    DMatchContainer() {}

    DMatchContainer(std::vector<cv::DMatch> dMatchList) {
        this->dMatchList = dMatchList;
    }

};
