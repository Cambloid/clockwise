#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H

#include <QString>
#include <QPixmap>

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

#include "Image/ImageLoader.h"

class ImageContainer {

private:
    QStringList fileCollection;
    QList<cv::Mat> ocv_MatList;

public:
    ImageContainer();
    ImageContainer(QList<cv::Mat> *imageCollection);
    ImageContainer(QStringList fileCollection);
    ~ImageContainer();

    void LoadAll();

    QList<cv::Mat> getOCV_MatList();
};


#endif
