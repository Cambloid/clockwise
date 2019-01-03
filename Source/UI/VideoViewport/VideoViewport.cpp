#include "VideoViewport.h"
#include "ui_VideoViewport.h"

#include <QPushButton>


// TODO:
// Create Panning Widget with ScrollArea and QWidget


VideoViewport::VideoViewport(QWidget *parent) : QMainWindow(parent), ui(new Ui::VideoViewport)
{
    ui->setupUi(this);

    this->initViewport();
    this->initEvents();

    //TODO:
    // Load file
    // Display File

}

VideoViewport::~VideoViewport()
{
    delete ui;
}


void VideoViewport::initViewport()
{

}


void VideoViewport::initEvents()
{

}




void VideoViewport::scaleVideo(int scale)
{


}
