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




// Private Methods
QString MainWindow::pickImage()
{
    return QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Images (*.png *.xpm *.jpg)"));
}

void MainWindow::presentImage(QString imageFile) {
    std::cout << "Present image:" << imageFile.toStdString() << std::endl;
    QPixmap bkgnd(imageFile);

    if(bkgnd.isNull()) {
        std::cout << "Pixmap is null" << std::endl;
    }

    ui->label->setPixmap(bkgnd);
}

//Event Handlers
void MainWindow::btnDetectFeatures_clicked() {
    std::cout << "btnDetectFeatures_clicked" << std::endl;
}

void MainWindow::btnLoadImage_clicked() {
    this->presentImage(this->pickImage());
    std::cout << "btnLoadImage_clicked" << std::endl;
}
