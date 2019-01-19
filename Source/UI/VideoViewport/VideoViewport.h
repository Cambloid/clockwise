#pragma once


#include <QDockWidget>

#include <QVBoxLayout>
#include <ZittelmenEngine.h>

class VideoViewport : public QDockWidget
{
    Q_OBJECT

public:
    explicit VideoViewport(QWidget *parent = nullptr);
    ~VideoViewport();

private:
	ZittelmenEngine *m_ZIengine;

};
