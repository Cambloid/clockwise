#include "ImageContainer.h"


ImageContainer::ImageContainer(QStringList fileCollection) {
    this->fileCollection = fileCollection;
}

ImageContainer::~ImageContainer() {

}

QList<cv::Mat> ImageContainer::getOCV_MatList() {
    return this->ocv_MatList;
}

void ImageContainer::LoadAll() {

    if(this->fileCollection.isEmpty()) {
        std::cout << "Container is empty" << std::endl;
        return;
    }
    foreach(const QString &str, this->fileCollection) {
       this->ocv_MatList.append(cv::imread(str.toStdString(), cv::IMREAD_COLOR ));
    }

}

