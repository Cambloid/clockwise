#pragma once


#include <QDockWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QTimer>

#include "ZittelmenEngine.h"

class Viewport3d : public QDockWidget
{
    Q_OBJECT

public:
    explicit Viewport3d(QWidget *parent = nullptr);
    ~Viewport3d();

	void initVulkanRender();
	void destroyVulkanRenderer();

protected:
	bool event(QEvent * event);
	
private slots:
	void timer_tick();

private:
	ZittelmenEngine *ziEngine = nullptr;
	QWidget *renderTarget;
	QTimer *renderTimer;

};
