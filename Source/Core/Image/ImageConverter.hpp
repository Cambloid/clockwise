#pragma once

#include <QPixmap>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

class ImageConverter {

public:
    static QPixmap ToQPixmap(cv::Mat ocvImage) {
        cv::Mat tmpImage = ocvImage.clone();
        cv::cvtColor(tmpImage, tmpImage, cv::COLOR_BGR2RGB);
        return QPixmap::fromImage(QImage(tmpImage.data, tmpImage.cols, tmpImage.rows, tmpImage.step, QImage::Format_RGB888));
    }

};
