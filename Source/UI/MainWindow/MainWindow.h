#pragma once

#include "Source/Core/Image/ImageLoader.hpp"
#include "Source/Core/Image/ImageContainer.h"
#include "Source/Core/Image/ImageConverter.hpp"
#include "Source/Core/Image/ImageUtils.hpp"

#include "Source/Core/FeatureDetection/DetectorManager.h"

#include "Source/UI/SettingsWindow/SettingsWindow.h"
#include "Source/Core/DTO/SettingsBase.h"
#include "Source/Core/DTO/SIFTDescriptorContainer.h"
#include "Source/Core/DTO/DMatchContainer.h"

#include "Source/Core/DescriptorExtractor/SIFTDescriptorExtractor.h"
#include "Source/Core/DTO/SIFTDescriptorContainer.h"

#include "Source/Core/FeatureMatching/FLANNMatcher.h"
#include "Source/Core/FeatureTracking/CSRTTracker.h"

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
    std::vector<ImageContainer> imgContainerList;
    std::vector<FeatureContainer> featureContainerList;

    std::vector<SIFTDescriptorContainer> descContainerList;
    std::vector<DMatchContainer> dmatchContainerList;

    SettingsBase settings;

private: // Private Methods
    QStringList pickImage();
    void presentImage();
    void manualSelectFeature();

private slots: // Events
    void btnLoadImage_clicked();
    void btnDetectFeatures_clicked();
    void btnMatchFeatures_clicked();
    void btnSettings_clicked();
    void sldCurrentImage_valueChanged();
    void btnManualSelectFeature_clicked();

protected:
    void resizeEvent(QResizeEvent* event) override;

};
