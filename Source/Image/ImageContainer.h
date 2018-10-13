#pragma once

#include <QString>
#include <QPixmap>

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class ImageContainer {

private:
    QString filePath;
    cv::Mat imageData;
    void loadImage();

public:
    ImageContainer();
    ImageContainer(cv::Mat image);
    ~ImageContainer();

    cv::Mat getImage();
};
