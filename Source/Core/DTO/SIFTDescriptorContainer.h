#pragma once

#include <QList>
#include <opencv2/core.hpp>

struct SIFTDescriptorContainer
{
    cv::Mat descriptor;

    SIFTDescriptorContainer() {}

    SIFTDescriptorContainer(cv::Mat descriptor) {
        this->descriptor = descriptor;
    }

};


