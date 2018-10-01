#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Register Events
    this->connect(ui->btnLoadImage,      SIGNAL(clicked()), this, SLOT(btnLoadImage_clicked()));
    this->connect(ui->btnDetectFeatures, SIGNAL(clicked()), this, SLOT(btnDetectFeatures_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::presentImage(QPixmap pixmap) {
    ///std::cout << "Present image:" << imageFile.toStdString() << std::endl;

    if(pixmap.isNull()) {
        std::cout << "Pixmap is null" << std::endl;
    }

    ui->label->setPixmap(pixmap);
}


//Event Handlers
void MainWindow::btnDetectFeatures_clicked() {
    std::cout << "btnDetectFeatures_clicked" << std::endl;
}

void MainWindow::btnLoadImage_clicked() {

    ImageLoader loader;
    ImageContainer imgContainer(loader.PickImage());
    imgContainer.LoadAll();

    // Load and present image
    //this->presentImage(imgContainer.getOCV_MatList().first());

}
