#pragma once

#include "Image/ImageLoader.hpp"
#include "Image/ImageContainer.h"
#include "Image/ImageConverter.hpp"
#include "Image/ImageUtils.hpp"

#include "FeatureDetection/DetectorManager.h"

#include "UI/SettingsWindow/SettingsWindow.h"
#include "DTO/SettingsBase.h"
#include "DTO/SIFTDescriptorContainer.h"
#include "DTO/DMatchContainer.h"

#include "DescriptorExtractor/SIFTDescriptorExtractor.h"
#include "DTO/SIFTDescriptorContainer.h"

#include "FeatureMatching/FLANNMatcher.h"


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
