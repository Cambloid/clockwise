#pragma once

#include <QMainWindow>

#include <QWheelEvent>
#include <QBoxLayout>
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
    Ui::VideoViewport *ui;

};
