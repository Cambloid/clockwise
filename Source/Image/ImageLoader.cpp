#include "ImageLoader.h"


ImageLoader::ImageLoader() {

}

ImageLoader::~ImageLoader() {


}

QStringList ImageLoader::PickImage() {
    return QFileDialog::getOpenFileNames(nullptr, "Open File", "/home", "Images (*.png *.xpm *.jpg)");
}
