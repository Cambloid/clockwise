#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Image/ImageLoader.h"
#include "Image/ImageContainer.h"
#include "FeatureDetection/ShiTomasiDetector.h"
#include "FeatureDetection/CornerHarrisDetector.h"

#include "Image/ImageConverter.hpp"

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>


#include <iostream>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ImageContainer imgContainer;

private:
    QStringList pickImage();
    void presentImage();

private slots: // Events
    void btnLoadImage_clicked();
    void btnDetectFeatures_clicked();
    void sldCurrentImage_ValueChanged();

protected:
    void resizeEvent(QResizeEvent* event) override;

};

#endif // MAINWINDOW_H
