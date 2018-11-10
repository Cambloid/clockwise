#pragma once

#include "Core/Image/ImageLoader.hpp"
#include "Core/Image/ImageContainer.h"
#include "Core/Image/ImageConverter.hpp"
#include "Core/Image/ImageUtils.hpp"

#include "Core/FeatureDetection/DetectorManager.h"

#include "UI/SettingsWindow/SettingsWindow.h"
#include "Core/DTO/SettingsBase.h"
#include "Core/DTO/SIFTDescriptorContainer.h"
#include "Core/DTO/DMatchContainer.h"

#include "Core/DescriptorExtractor/SIFTDescriptorExtractor.h"
#include "Core/DTO/SIFTDescriptorContainer.h"

#include "Core/FeatureMatching/FLANNMatcher.h"

#include "Core/FeatureTracking/KLTFeatureTracker.h"

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

/*!

*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private: // Private instancevariables
    Ui::MainWindow *ui;
    QList<ImageContainer> imgContainerList;
    QList<FeatureContainer> featureContainerList;

    QList<SIFTDescriptorContainer> descContainerList;
    std::vector<DMatchContainer> dmatchContainerList;

    SettingsBase settings;

private: // Private Methods
    QStringList pickImage();
    void presentImage();

private slots: // Events
    void btnLoadImage_clicked();
    void btnDetectFeatures_clicked();
    void btnMatchFeatures_clicked();
    void btnSettings_clicked();
    void sldCurrentImage_valueChanged();

protected:
    void resizeEvent(QResizeEvent* event) override;

};
