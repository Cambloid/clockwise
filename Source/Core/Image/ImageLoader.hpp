#pragma once

#include "Core/Image/ImageContainer.h"

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

    static std::vector<ImageContainer> BulkLoadImage(QStringList filePathList) {
        std::vector<ImageContainer> images;
        foreach(QString str, filePathList) {
            images.push_back(ImageContainer(cv::imread(str.toStdString(), cv::IMREAD_COLOR)));
        }
        return images;
    }

    static QStringList PickImages() {
        return QFileDialog::getOpenFileNames(nullptr, "Open File", "home", "Images (*.png *.jpg *.mp4)");
    }

    static std::vector<ImageContainer> LoadVideo(QString filePath) {
        if(filePath.isNull() || filePath.isEmpty()) {
            std::cout << "Filepath is null or empty" << std::endl;
            return std::vector<ImageContainer>();
        }

        cv::VideoCapture video(filePath.toStdString());
        std::vector<ImageContainer> images;
        if(video.isOpened()) {
            cv::Mat videoFrame;
            while(true) {

                video >> videoFrame;

                if (videoFrame.empty())
                      break;

                images.push_back(videoFrame.clone());
            }
        }
        return images;
    }




};
