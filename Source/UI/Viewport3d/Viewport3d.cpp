#include "Viewport3d.h"
#include <Qt3DExtras/Qt3DExtras>

Viewport3d::Viewport3d(QWidget *parent) : QDockWidget(parent) //, ui(new Ui::Viewport3d)
{
	this->renderTarget = new QWidget(this);
	this->setWidget(this->renderTarget);
}

Viewport3d::~Viewport3d()
{
	delete this->m_ZIengine;
}

void Viewport3d::initVulkanRender()
{
	this->m_ZIengine = new ZittelmenEngine();
	this->m_ZIengine->setTargetRenderSurface(this->renderTarget);
	this->m_ZIengine->initVulkanRenderer();
}

void Viewport3d::paintEvent(QPaintEvent * event)
{
	//this->m_ZIengine->renderFrame();
}

bool Viewport3d::event(QEvent* event)
{
	if (event->type() == QEvent::Resize) {
		QResizeEvent *resizeEvent = static_cast<QResizeEvent*>(event);
		this->m_ZIengine->resize(resizeEvent->size().width(), resizeEvent->size().height());
	} else {
		if (this->m_ZIengine != nullptr && this->m_ZIengine->initialized()) {
			this->m_ZIengine->renderFrame();
		}
	}

	return QDockWidget::event(event);
}
