#include "Viewport3d.h"
#include <Qt3DExtras/Qt3DExtras>

Viewport3d::Viewport3d(QWidget *parent) : 
	QDockWidget(parent)
{
	this->renderTarget = new QWidget(this);
	this->setWidget(this->renderTarget);

	this->renderTimer = new QTimer(this);
	connect(this->renderTimer, &QTimer::timeout, this, &Viewport3d::timer_tick);
}

Viewport3d::~Viewport3d()
{
	this->destroyRenderer();
}

void Viewport3d::initVulkanRender()
{

	this->ziEngine.reset(new ZittelmenEngine());
	this->ziEngine->setTargetRenderSurface(this->renderTarget);
	this->ziEngine->initialize();

	this->renderTimer->start(0);

}

void Viewport3d::destroyRenderer()
{
	this->ziEngine.reset();
}

void Viewport3d::timer_tick()
{



	this->ziEngine->renderFrame();
}

bool Viewport3d::event(QEvent* event)
{
	if (event->type() == QEvent::Resize) {
		QResizeEvent *resizeEvent = static_cast<QResizeEvent*>(event);
		this->ziEngine->resize(resizeEvent->size().width(), resizeEvent->size().height());
	}

	return QDockWidget::event(event);
}

