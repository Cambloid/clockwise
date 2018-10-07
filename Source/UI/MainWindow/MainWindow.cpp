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
    this->connect(ui->btnLoadImage,      SIGNAL(clicked()),         this, SLOT(btnLoadImage_clicked()));
    this->connect(ui->btnDetectFeatures, SIGNAL(clicked()),         this, SLOT(btnDetectFeatures_clicked()));
    this->connect(ui->btnSettings,       SIGNAL(clicked()),         this, SLOT(btnSettings_clicked()));
    this->connect(ui->sldCurrentImage,   SIGNAL(valueChanged(int)), this, SLOT(sldCurrentImage_valueChanged()));

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

    if(imgContainer.getOCV_MatList().count() <= 0) {
        return;
    }

    cv::Mat currImage = imgContainer.getOCV_MatList().at(currIdx);
    QPixmap pixmapImg = ImageConverter::ToQPixmap(currImage);

    ui->lblImage->setPixmap(pixmapImg.scaled(ui->lblImage->width(), ui->lblImage->height(), Qt::KeepAspectRatio));
}


/*!
Event Handlers
*/
void MainWindow::btnDetectFeatures_clicked() {
    std::cout << "btnDetectFeatures_clicked" << std::endl;

    DetectorManager detector(this->settings);
    this->imgContainer = detector.StartDetection(this->imgContainer);

    this->presentImage();
}

/*!

*/
void MainWindow::btnLoadImage_clicked() {

    ImageLoader loader;
    ImageContainer imgContainer(loader.PickImage());

    imgContainer.LoadAll();

    this->imgContainer = imgContainer;
    ui->sldCurrentImage->setRange(0, imgContainer.getOCV_MatList().count() - 1);

    this->presentImage();
}

/*!

*/
void MainWindow::sldCurrentImage_valueChanged() {
    this->presentImage();
}

/*!

*/
void MainWindow::btnSettings_clicked() {
    SettingsWindow settingsWindow(this->settings);
    settingsWindow.exec();
}

/*!

*/
void MainWindow::resizeEvent(QResizeEvent *event) {
    this->presentImage();
}
