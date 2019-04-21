#include "Viewport3d.h"

Viewport3d::Viewport3d(QWidget *parent) : QDockWidget(parent)
{
	this->renderTarget = new QWidget(this);
	this->setWidget(this->renderTarget);
	this->renderTimer = new QTimer(this);
	
	QObject::connect(this->renderTimer, &QTimer::timeout, this, &Viewport3d::timer_tick);
}

Viewport3d::~Viewport3d()
{
	this->destroyRenderer();
}

void Viewport3d::initVulkanRender()
{


	{
		this->ziEngine = std::make_unique<ZiEngine>();
		this->ziEngine->SetTargetRenderSurface(this->renderTarget);
		std::shared_ptr<ZiScene> scene = std::make_shared<ZiScene>();
		std::shared_ptr<ZiMesh> simpleMesh = std::make_shared<ZiMesh>(
			ZiMesh::GetQuadVertexCollection(),
			ZiMesh::GetQuadVertexIndexCollection(),
			ZiTexture("D:/coretrack_devel/texture.jpg")
			);
		scene->AddMesh(simpleMesh);
		this->ziEngine->SetScene(scene);


		this->ziEngine->Initialize();
	}


	this->renderTimer->start(0); 
}

void Viewport3d::destroyRenderer()
{
	//this->ziEngine.reset();
}

void Viewport3d::timer_tick()
{
	this->ziEngine->RenderFrame();
}

bool Viewport3d::event(QEvent* event)
{
	if (event->type() == QEvent::Resize) {
		QResizeEvent *resizeEvent = static_cast<QResizeEvent*>(event);

		this->ziEngine->Resize(
			resizeEvent->size().width(), 
			resizeEvent->size().height()
		);

	} else if (event->type() == QEvent::Close) {
		this->ziEngine->Destroy();
	}

	return QDockWidget::event(event);
}

