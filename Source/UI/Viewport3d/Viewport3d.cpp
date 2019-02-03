#include "Viewport3d.h"
#include <Qt3DExtras/Qt3DExtras>

Viewport3d::Viewport3d(QWidget *parent) : QDockWidget(parent) //, ui(new Ui::Viewport3d)
{
	this->renderTarget = new QWidget(this);
	this->setWidget(this->renderTarget);

	this->renderTimer = new QTimer(this);
	connect(this->renderTimer, SIGNAL(timeout()), this, SLOT(timer_tick()));
}

Viewport3d::~Viewport3d()
{
	this->destroyVulkanRenderer();
}

void Viewport3d::initVulkanRender()
{
	this->ziEngine = new ZittelmenEngine();
	this->ziEngine->setTargetRenderSurface(this->renderTarget);
	this->ziEngine->initVulkanRenderer();

	this->renderTimer->start(0);
}

void Viewport3d::destroyVulkanRenderer()
{
	this->renderTimer->stop();
	delete this->ziEngine;
}

bool Viewport3d::event(QEvent* event)
{
	if (event->type() == QEvent::Resize) {
		QResizeEvent *resizeEvent = static_cast<QResizeEvent*>(event);
		this->ziEngine->resize(resizeEvent->size().width(), resizeEvent->size().height());

	} else if(event->type() == QEvent::Close) {
		this->destroyVulkanRenderer();
	}

	return QDockWidget::event(event);
}


void Viewport3d::timer_tick() {

	this->ziEngine->renderFrame();
}