#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QStringList>
#include <QFileDialog>
#include <QDialog>

class ImageLoader {

public:
    ImageLoader();
    ~ImageLoader();

    QStringList PickImage();

};

#endif
