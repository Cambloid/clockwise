#include "UI/MainWindow/MainWindow.h"
#include "ui_mainwindow.h"

/*!

*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Fix to resize MainWindow smaller
    ui->lblImage->setMinimumSize(1, 1);


    // Register Events
    this->connect(ui->btnDetectFeatures,        SIGNAL(clicked()),         this, SLOT(btnDetectFeatures_clicked()));

    this->connect(ui->btnMatchFeatures,         SIGNAL(clicked()),         this, SLOT(btnMatchFeatures_clicked()));
    this->connect(ui->sldCurrentImage,          SIGNAL(valueChanged(int)), this, SLOT(sldCurrentImage_valueChanged()));
    this->connect(ui->btnManualSelectFeature,   SIGNAL(clicked()),         this, SLOT(btnManualSelectFeature_clicked()));

	//this->connect(ui-actionImport)

	this->connect(ui->actionImport, &QAction::triggered, this, &MainWindow::mnuImport_clicked);
	this->connect(ui->action3D_View, &QAction::triggered, this, &MainWindow::mnu3DView_clicked);
	this->connect(ui->actionFootage_viewer, &QAction::triggered, this, &MainWindow::mnuFootage_viewer_clicked);
	this->connect(ui->actionSettings, &QAction::triggered, this, &MainWindow::mnuSettings_clicked);

}

/*!

*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*!

*/
void MainWindow::presentImage() {
    int currIdx = ui->sldCurrentImage->value();

    if(this->imgContainerList.size() <= 0 || this->featureContainerList.size() <= 0) {

        std::cout << "imgContainerList count:" << this->imgContainerList.size() << std::endl;
        std::cout << "featureContainerList count:" << this->featureContainerList.size() << std::endl;

        return;

    }

    cv::Mat currImage = ImageUtils::DrawKeypointFeatures(imgContainerList[currIdx].getImage(), this->featureContainerList[currIdx]);
    QPixmap pixmapImg = ImageConverter::ToQPixmap(currImage);

    ui->lblImage->setPixmap(pixmapImg.scaled(ui->lblImage->width(), ui->lblImage->height(), Qt::KeepAspectRatio));
}

/*!
 *
*/
void MainWindow::manualSelectFeature()
{
    // Get current image

    // Select rectangle and add this as keypoint to feature container



    int currIdx = ui->sldCurrentImage->value();

    if(this->imgContainerList.size() > currIdx) {
        cv::Mat currImage = imgContainerList[currIdx].getImage();

        // Define initial bounding box
        cv::Rect2d bbox(287, 23, 86, 320);

        // Uncomment the line below to select a different bounding box
        bbox = cv::selectROI(currImage, false);


        if(this->featureContainerList.size() > 0) {

            // Set center of selected rectangle as keypoint
            this->featureContainerList.at(0).keyPointList.at(0).pt.x = float(bbox.x + (bbox.width / 2));
            this->featureContainerList.at(0).keyPointList.at(0).pt.y = float(bbox.y + (bbox.height / 2));

            // Display bounding box.
            //cv::rectangle(currImage, bbox, cv::Scalar( 255, 0, 0 ), 2, 1 );

        } else {
            // TODO
        }



    }


}

/*!
    Event Handlers
*/
void MainWindow::btnDetectFeatures_clicked() {
    std::cout << "btnDetectFeatures_clicked" << std::endl;

    DetectorManager detector(this->settings);
    this->featureContainerList = detector.StartDetection(this->imgContainerList);

    this->presentImage();
}

/*!

*/
void MainWindow::btnMatchFeatures_clicked()
{
    if(this->imgContainerList.size() != this->featureContainerList.size()) {
        return;
    }

    SettingsFeatureTracker tmpSettings;
    CSRTTracker tracker(tmpSettings);

    tracker.StartTracking(this->imgContainerList, this->featureContainerList);

    return;

    SIFTDescriptorExtractor extractor;
    this->descContainerList = extractor.StartExtraction(this->imgContainerList, this->featureContainerList);

    std::cout << "descriptorList count " << this->descContainerList.size() << std::endl;

    FLANNMatcher matcher(this->imgContainerList, this->descContainerList);
    this->dmatchContainerList = matcher.StartMatching();



    std::cout << "DMatchContainer List count " << this->dmatchContainerList.size() << std::endl;
}

/*!

*/
void MainWindow::sldCurrentImage_valueChanged() {
    this->presentImage();
}


/*!

*/
void MainWindow::btnManualSelectFeature_clicked()
{
    this->manualSelectFeature();
}

/*!

*/
void MainWindow::mnu3DView_clicked()
{
	Viewport3d *viewport = new Viewport3d(this);
	this->addDockWidget(Qt::BottomDockWidgetArea, viewport);
}

/*!

*/
void MainWindow::mnuFootage_viewer_clicked()
{
	FootageViewer *viewer = new FootageViewer();
	this->addDockWidget(Qt::BottomDockWidgetArea, viewer);
}

/*!

*/
void MainWindow::mnuSettings_clicked()
{
	SettingsWindow settingsWindow(this->settings);
	settingsWindow.exec();

	if (settingsWindow.result() == QDialog::Accepted) {
		this->settings = settingsWindow.getDataFromFields();
	}
}

void MainWindow::mnuImport_clicked()
{
	QStringList imageList = ImageLoader::PickImages();

	if (imageList.size() <= 0) {
		return;
	}

	//Check file extension
	QFileInfo info(imageList.at(0));

	std::cout << "File suffix:" << info.suffix().toStdString() << std::endl;

	if (info.suffix().toStdString() == "mp4") {
		this->imgContainerList = ImageLoader::LoadVideo(imageList.at(0));
	}
	else {
		this->imgContainerList = ImageLoader::BulkLoadImage(imageList);
	}


	ui->sldCurrentImage->setRange(0, this->imgContainerList.size() - 1);

	this->presentImage();
}

/*!

*/
void MainWindow::resizeEvent(QResizeEvent *event) {
    this->presentImage();
}
