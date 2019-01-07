#pragma once

#include <QMainWindow>

#include <QWheelEvent>
#include <QBoxLayout>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QWidget>

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
    void initViewport();
    void initEvents();


private slots: // Events
    void scaleVideo(int scale);


private:
    Ui::VideoViewport *ui;

    QGraphicsScene     *m_scene        = nullptr;
    QGraphicsVideoItem *m_videoItem    = nullptr;
    QMediaPlayer       *m_mediaPlayer  = nullptr;

};
