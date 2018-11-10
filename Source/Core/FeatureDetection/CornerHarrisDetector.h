#pragma once

#include "Core/Image/ImageContainer.h"
#include "Core/DTO/FeatureContainer.h"

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>


class CornerHarrisDetector {

private:
    int threshold = 100;


public: // Konstruktor
    CornerHarrisDetector();
    ~CornerHarrisDetector();

public:
    int getThreshold();
    void setThreshold(int threshold);
    QList<FeatureContainer> StartDetection(QList<ImageContainer> &imageContainerList);

};
