#pragma once

#include "Core/Image/ImageLoader.hpp"
#include "Core/Image/ImageContainer.h"
#include "Core/Image/ImageConverter.hpp"
#include "Core/Image/ImageUtils.hpp"

#include "Core/FeatureDetection/DetectorManager.h"

#include "UI/SettingsWindow/SettingsWindow.h"
#include "UI/Viewport3d/Viewport3d.h"
#include "UI/FootageViewer/FootageViewer.h"
#include "UI/NodeGraph/NodeGraph.h"

#include "Core/DTO/SettingsBase.h"
#include "Core/DTO/SIFTDescriptorContainer.h"
#include "Core/DTO/DMatchContainer.h"

#include "Core/DescriptorExtractor/SIFTDescriptorExtractor.h"
#include "Core/DTO/SIFTDescriptorContainer.h"

#include "Core/FeatureMatching/FLANNMatcher.h"
#include "Core/FeatureTracking/CSRTTracker.h"


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
    void btnDetectFeatures_clicked();
    void btnMatchFeatures_clicked();

    void sldCurrentImage_valueChanged();
    void btnManualSelectFeature_clicked();

	void mnuNodeEditor_clicked();
	void mnu3DView_clicked();
	void mnuFootage_viewer_clicked();
	void mnuSettings_clicked();
	void mnuImport_clicked();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
	std::shared_ptr<Viewport3d> viewport3d;
	std::shared_ptr<FootageViewer> footageViewer;
	std::shared_ptr<NodeGraph> nodeGraph;
	
	//Viewport3d *viewport3d;

};
