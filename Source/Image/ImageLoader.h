#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QStringList>
#include <QFileDialog>
#include <QDialog>

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

class ImageLoader {
public:
    ImageLoader();
    ~ImageLoader();

    QStringList PickImage();
    QList<cv::Mat> BulkLoadImage(QStringList &imageList);
};

#endif
