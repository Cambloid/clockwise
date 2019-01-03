#include "VideoViewport.h"
#include "ui_VideoViewport.h"

#include <QVulkanInstance>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

VideoViewport::VideoViewport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VideoViewport)
{
    ui->setupUi(this);



}

VideoViewport::~VideoViewport()
{
    delete ui;
}
