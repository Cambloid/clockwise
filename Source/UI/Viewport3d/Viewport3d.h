#pragma once


#include <QDockWidget>

#include <QVBoxLayout>
#include <ZittelmenEngine.h>

class Viewport3d : public QDockWidget
{
    Q_OBJECT

public:
    explicit Viewport3d(QWidget *parent = nullptr);
    ~Viewport3d();

private:
	ZittelmenEngine *m_ZIengine;

};
