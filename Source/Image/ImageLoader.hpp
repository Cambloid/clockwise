#pragma once

#include "Image/ImageContainer.h"

#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include <QFileDialog>
#include <QString>
#include <QStringList>
#include <QList>

class ImageLoader {

public:
    ImageLoader();
    ~ImageLoader();

public:
    static ImageContainer LoadImage(QString filePath) {
        return ImageContainer(cv::imread(filePath.toStdString(), cv::IMREAD_COLOR));
    }

    static QList<ImageContainer> BulkLoadImage(QStringList filePathList) {
        QList<ImageContainer> images;
        foreach(QString str, filePathList) {
            images.append(ImageContainer(cv::imread(str.toStdString(), cv::IMREAD_COLOR)));
        }
        return images;
    }

    static QStringList PickImages() {
        return QFileDialog::getOpenFileNames(nullptr, "Open File", "home", "Images (*.png *.xpm *.jpg)");
    }

};
