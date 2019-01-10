#include "Core/Image/ImageContainer.h"


ImageContainer::ImageContainer() {

}

ImageContainer::ImageContainer(cv::Mat image) {
    this->imageData = image;
}

ImageContainer::~ImageContainer() {

}

cv::Mat ImageContainer::getImage() {
    return this->imageData;
}
