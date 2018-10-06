#include "ImageContainer.h"

ImageContainer::ImageContainer() {

}

ImageContainer::ImageContainer(QList<cv::Mat> *imageCollection) {
    this->ocv_MatList = *imageCollection;
}

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

    ImageLoader loader;
    this->ocv_MatList = loader.BulkLoadImage(this->fileCollection);
}

