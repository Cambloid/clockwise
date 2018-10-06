#include "ImageLoader.h"


ImageLoader::ImageLoader() {

}

ImageLoader::~ImageLoader() {


}

QStringList ImageLoader::PickImage() {
    return QFileDialog::getOpenFileNames(nullptr, "Open File", "/home", "Images (*.png *.xpm *.jpg)");
}

QList<cv::Mat> ImageLoader::BulkLoadImage(QStringList &imageList)
{
    QList<cv::Mat> ocv_MatList;
    foreach(QString str, imageList) {
        ocv_MatList.append(cv::imread(str.toStdString(), cv::IMREAD_COLOR));
    }
    return ocv_MatList;
}
