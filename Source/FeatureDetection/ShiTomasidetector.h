#ifndef SHITOMASIDETECTOR_H
#define SHITOMASIDETECTOR_H

#include "Image/ImageContainer.h"

#include <QList>

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

class ShiTomasiDetector
{
public:
    ShiTomasiDetector();
    ~ShiTomasiDetector();
    ImageContainer StartDetection(ImageContainer &imageContainer);
};

#endif // SHITOMASIDETECTOR_H
