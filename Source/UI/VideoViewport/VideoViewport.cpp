#include "VideoViewport.h"
#include "ui_VideoViewport.h"


// TODO:
// Create Panning Widget with ScrollArea and QWidget


//#include <ZittelmenEngine.h>

VideoViewport::VideoViewport(QWidget *parent) : QMainWindow(parent), ui(new Ui::VideoViewport)
{
    ui->setupUi(this);

    //ZittelmenEngine engine;

    //QWidget *wrapper = QWidget::createWindowContainer(engine.getVulkanWindow());

    //this->initViewport();
    //this->initEvents();

    //TODO:
    // Load file
    // Display File

}

VideoViewport::~VideoViewport()
{
    delete ui;
}
