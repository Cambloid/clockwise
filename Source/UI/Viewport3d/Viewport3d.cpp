#include "Viewport3d.h"

#include <Qt3DExtras/Qt3DExtras>

//#include "ui_Viewport3d.h"

Viewport3d::Viewport3d(QWidget *parent) : QDockWidget(parent) //, ui(new Ui::Viewport3d)
{
	this->m_ZIengine = new ZittelmenEngine();
	
	QWidget renderTarget(this);
	this->m_ZIengine->setTargetRenderSurface(this);


	//QVBoxLayout layout;
	//QWidget *wrapper = QWidget::createWindowContainer(m_ZIengine->getQt3DWindow(), this);
	//layout.addWidget(wrapper);


	this->setWidget(&renderTarget);
	
}

Viewport3d::~Viewport3d()
{
	delete this->m_ZIengine;
}

void Viewport3d::initVulkanRender()
{
	this->m_ZIengine->initVulkanRenderer();
}
