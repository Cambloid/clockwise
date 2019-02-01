#pragma once


#include <QDockWidget>

#include <QVBoxLayout>
#include <ZittelmenEngine.h>

#include <QWidget>

class Viewport3d : public QDockWidget
{
    Q_OBJECT

public:
    explicit Viewport3d(QWidget *parent = nullptr);
    ~Viewport3d();

	void initVulkanRender();

protected:
	void paintEvent(QPaintEvent *event);
	bool event(QEvent * event);

private:
	ZittelmenEngine *m_ZIengine = nullptr;
	QWidget *renderTarget;
};
