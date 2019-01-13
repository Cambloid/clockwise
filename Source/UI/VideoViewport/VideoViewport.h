#pragma once

#include <QMainWindow>
#include <ZittelmenEngine.h>

namespace Ui {
 class VideoViewport;
}

class VideoViewport : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoViewport(QWidget *parent = nullptr);
    ~VideoViewport();


private:
    Ui::VideoViewport *ui;
	ZittelmenEngine *m_ZIengine;

};
