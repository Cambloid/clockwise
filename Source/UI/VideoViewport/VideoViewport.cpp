#include "VideoViewport.h"
#include "ui_VideoViewport.h"

VideoViewport::VideoViewport(QWidget *parent) : QMainWindow(parent), ui(new Ui::VideoViewport)
{
	ui->setupUi(this);

	this->m_ZIengine = new ZittelmenEngine();
	
	QWidget *wrapper = QWidget::createWindowContainer(m_ZIengine->getVulkanWindow(), this);
	ui->verticalLayout->addWidget(wrapper);

}

VideoViewport::~VideoViewport()
{
	delete this->m_ZIengine;
	delete ui;
}
