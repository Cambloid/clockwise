#include "VideoViewport.h"


//#include "ui_VideoViewport.h"

VideoViewport::VideoViewport(QWidget *parent) : QDockWidget(parent) //, ui(new Ui::VideoViewport)
{
	this->m_ZIengine = new ZittelmenEngine();
	


	QVBoxLayout layout;
	QWidget *wrapper = QWidget::createWindowContainer(m_ZIengine->getVulkanWindow(), this);
	layout.addWidget(wrapper);


	this->setWidget(wrapper);

}

VideoViewport::~VideoViewport()
{
	delete this->m_ZIengine;
}
